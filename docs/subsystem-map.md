# GEDE01 subsystem map

This is an address-first inventory for modding priorities. Ranges marked
**anchor** are individual DTK/Ghidra function boundaries with direct string or
call evidence; ranges marked **band** contain multiple anchors but are not yet
claimed as exclusive translation-unit ownership. Names remain provisional until
types and callers are recovered.

| Subsystem | Game-code range | Evidence | Confidence |
| --- | --- | --- | --- |
| Sanity/insanity effects | `0x8006F6A4-0x800A09D8` (band) | Direct string xrefs include `Ins: Timeline Visitation` in `fn_8006F6A4`, bleeding-wall effect diagnostics in `fn_80089394`, blood-pool effects in `fn_80089EE8`, ceiling-room insanity in `fn_8009E5C4`, and poltergeist-book effects in `fn_800A04BC`/`fn_800A079C`. | High that these are sanity-effect anchors; medium that the whole band is one subsystem. |
| Entity/actor and character data | `0x800721B0-0x8007513C` (gameplay anchors); `0x80138FE4-0x801390D4` and `0x801E97D4-0x801E995C` (engine anchors) | The first band directly references `ed_chrs.dat`, summon-camera data, and a Bonethief stalking/path diagnostic. Later anchors reference player animation tables and `Parse_NpcHeader_From_ByteStream()`. | High for anchors, low for continuous ownership. |
| Rendering/camera | `0x800C2708-0x800C280C` (camera anchor); `0x801EF400-0x801F5980` (engine band) | Direct references to `Camera01`, `SKEngine_Render.c`, and `SkEngine_AnimTexture.c`; the engine band lies immediately before the Nintendo GX archive beginning near `0x80222B30`. | High for renderer/animation anchors. |
| Audio/SFX/music | `0x80050B08-0x80052218` (game sound query); `0x801A9488-0x801AC2E8` (core audio band) | Direct xrefs to `GS_Query_Weapon_Sound`, `sd_sound.c`, `/audio/effects/ed_fx.*`, and `SoundSource %d`. A cinematic-audio call-site anchor also exists at `0x8016B4B4-0x8016B5CC`. | High for anchors and core band. |

The sanity row is expanded into an entry-point and structure map in
`docs/sanity-system.md`. That map separates effect registration functions from
per-frame/action callbacks and records only fields visible in repeated code.

## Entity and character anchors

- `fn_800721B0` (`0x800721B0-0x80072354`) initializes a fixed-stride character
  table at `0x80313120`. The observed stride is `0xE0`; the function clears a
  32-byte selection table at `0x80244680`, opens `ed_chrs.dat`, and reads records
  into the table. This is the strongest current game-side character-database
  loader anchor.
- `fn_80072354` computes `0x80313120 + index * 0xE0`, while `fn_80072368` scans
  175 entries and compares the word at record `+0x04`. These two leaves expose a
  concrete table shape without assigning semantic names to the remaining fields.
- `fn_800723A8` (`0x800723A8-0x8007249C`) reopens `ed_chrs.dat` and reads a
  selected record, making it a bounded per-character load/update path rather than
  a broad subsystem guess.
- `fn_801E97D4` (`0x801E97D4-0x801E995C`) is the engine-side NPC header parser.
  It checks the serialized header size against `0x2C`, emits the direct
  `Parse_NpcHeader_From_ByteStream()` diagnostic on mismatch, and relocates
  variable-length fields observed at header offsets `+0x08`, `+0x10`, and
  `+0x18`. These offsets are evidence for future typing, not final field names.

## Supporting data ranges

- Audio enum/debug strings start near `.data` `0x8023C830`; effect archive paths
  begin near `0x8023E868`; weapon-sound diagnostics occur at `0x8024104C`.
- Sanity globals and diagnostics occupy `.data` around
  `0x8023ED60-0x802456B8`, including `gMaxSanity`, `SanityMkr99`, and the named
  insanity-effect strings. This is a broad evidence range, not one owned object.
- Music and cinematic path tables begin around `.data` `0x80248DA8`.

Addresses above come from the verified GEDE01 DOL mapping (`.text`
`0x800068E0-0x80237EDC`, `.data` file offset `0x238940` loaded at
`0x8023B940`). DTK supplies function boundaries; direct PowerPC `lis/addi`
address constructions and the planned Ghidra xref view identify the string
anchors. No range is promoted to a source TU solely from this classification.

## Modding depth order

1. Sanity-effect anchors, because named effects and their marker/region strings
   provide the clearest behavior-to-code path.
2. Audio core at `0x801A9488-0x801AC2E8`, because archive paths and sound-source
   diagnostics expose stable content hooks.
3. Renderer/animation anchors near `0x801EF400`, then their callers, to separate
   engine presentation from Nintendo GX internals.
4. Character/entity loaders and gameplay actors after the shared character-file
   structures are typed.
