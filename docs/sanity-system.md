# Sanity-effect subsystem map

This map uses DTK function boundaries, direct calls, string constructions, and
repeated field accesses from GEDE01. Names describe observed roles and remain
provisional until matching source supplies types.

## Shared entry points

| Address | Observed role | Evidence |
| --- | --- | --- |
| `fn_8006DEF8` | Register/schedule an effect callback | Effect initializers repeatedly pass `(controller, channel, callback, controller, duration, ...)`; the selected slot is then configured at a `0x2C` stride. |
| `fn_8006ED3C` | Resolve an effect record by controller/channel | Initializers and callbacks pass the controller plus a small channel and an output index pointer; returned records are checked and have a halfword state field at `+0x08`. |
| `fn_800FD40C` | Attach a diagnostic/display name | Initializers pass `controller + 0x18`, a named insanity string, a slot-derived pointer, and zero. |
| `fn_80046774` | External Timeline Visitation trigger path | Calls `fn_8006F6A4` at `0x800467CC`. |
| `fn_8006BFB4` | Gameplay caller of the one-book poltergeist path | Calls `fn_800A04BC` at `0x8006C49C`. |
| `fn_8006FE40` | Gameplay caller of the later poltergeist path | Calls `fn_800A079C` at `0x8006FF7C`. |
| `fn_801A9FA4` | Audio-side caller into sinking-feeling logic | Calls `fn_800A1060` at `0x801AA0E0`. |

## Effect anchors

| Effect | Registration/initializer | Action or state callbacks | Direct data evidence |
| --- | --- | --- | --- |
| Target marker | `fn_80087A24` | `fn_80087BA8`, `fn_80087D64`, `fn_80087EC4`, `fn_80088298` | `"Insanity: Target Marker"` at `0x80245090`. |
| Attack camera | `fn_80088890` | adjacent camera callbacks not yet typed | `"Insanity: Attack Camera"` at `0x802450A8`. |
| Horror camera shake | `fn_80088C04` | adjacent camera callbacks not yet typed | `"Ins: Horror Cam Shake"` at `0x802450C0`. |
| Bleeding walls | `fn_80089204` | `fn_80089394`, `fn_80089754` | Name at `0x802450D8`; particle-failure diagnostic at `0x802450F4`. |
| Blood bath | `fn_800898E0` | callbacks registered inside that initializer | Name at `0x8024514C`. |
| Blood-pool ceiling drip | `fn_80089EE8` | state logic within the same anchor and its registered callbacks | Name at `0x80245164`. |
| Timeline visitation | `fn_8009DF38` | `fn_8009E0D4`, `fn_8009E130` | Name at `0x80245448`; initializer schedules three callbacks with room-dependent durations. |
| Walk on ceiling | `fn_8009E39C` | `fn_8009E5C4` and adjacent callbacks | Name at `0x80245464`; invalid-room diagnostic at `0x8024547C`. |
| Illusions of grandeur | `fn_8009DCA4` | callbacks not yet typed | `"Ins: Illusions of Grandeur"` at `0x80245414`. |
| Phantom creatures | `fn_8009DE50` | callbacks not yet typed | `"Ins: Phantom Creatures"` at `0x80245430`. |
| Edwards ghost cinematic | `fn_8009E710` | callbacks not yet typed | `"Insanity: Edwards Ghost Cine"` at `0x802454C8`. |
| Zombie | `fn_8009E8E0` | callbacks not yet typed | `"Insanity: Zombie"` at `0x802454E8`. |
| Alex phone call | `fn_8009EC34` | callbacks not yet typed | `"Ins: Alex Phone Call"` at `0x802454FC`. |
| Bug crawl | `fn_8009ED44` | callbacks not yet typed | `"Insanity: Bug Crawl"` at `0x80245514`. |
| Controller missing | `fn_8009F07C` | callbacks not yet typed | `"Ins: Controller Not found"` at `0x80245528`. |
| Ammo pickup | `fn_8009F41C` | callbacks not yet typed | `"Insanity: Ammo Pickup"` at `0x80245544`. |
| Locked in room | `fn_8009F534` | callbacks not yet typed | `"Ins: Locked in Room"` at `0x8024555C`. |
| To be continued | `fn_8009F7D4` | callbacks not yet typed | `"Insanity: To be Continued"` at `0x80245570`. |
| TV shutoff | `fn_8009F99C` | callbacks not yet typed | `"Ins: TV Shut Off"` at `0x8024558C`. |
| Enemy one-hit kill | `fn_8009FEF0` | callbacks not yet typed | `"Ins: Enemy One Hit Kill"` at `0x802455A0`. |
| Expand/shrink player | `fn_800A0018` | mode-specific callbacks not yet typed | Names at `0x802455B8` and `0x802455D0`. |
| Poltergeist book | direct actions `fn_800A04BC`, `fn_800A079C` | internal state paths | One-book failure diagnostic at `0x802455E8`; caller xrefs listed above. |
| Sinking feeling | `fn_800A1150` | `fn_800A1060`, `fn_800A1580` | Name at `0x802456B8`; dispatch tables at `0x80245634` and `0x802456D4`. |

## Repeated structure observations

- The first argument to initializers is a controller-like object. `+0xC4` points
  to an effect runtime object, and runtime `+0x15C` points to a larger mutable
  state block. Bleeding walls clears that block in two spans (`0x000-0xAFF` and
  `0xB00-0x173F`) before registering callbacks.
- Effect slot addressing repeatedly uses `controller + index * 0x2C`, with byte
  fields observed at effective offsets `+0x68`, `+0x6A`, and `+0x6B`. Those bytes
  hold small state/mode values; their semantic names are not yet proven.
- The record returned by `fn_8006ED3C` has a halfword at `+0x08` that initializers
  clear. This is likely per-effect state, but the map does not yet call it an enum.
- Timeline visitation mutates runtime flags at `+0x20`, including bit `0x4`, and
  schedules three instances of one callback. This makes `fn_8009DF38` the best
  current starting point for a controllable sanity-effect trigger mod.
- The contiguous name block `0x80245090-0x802456D2` is an effect catalog, not a
  proven array: it mixes aligned strings, diagnostics, unrelated AI strings, and
  jump tables. It must not be modeled as one flat structure.
- Direct `lis`/`addi` xrefs now tie more than twenty named effects to closed DTK function
  boundaries. That establishes an initializer catalog, but does not by itself
  prove the selection weights or whether every name corresponds to an enabled
  retail effect.

## Next xref passes

1. Type the `fn_8006DEF8` and `fn_8006ED3C` arguments from three independently
   matched effect initializers.
2. Trace writes to runtime `+0x20` and the slot bytes to distinguish lifecycle,
   input gating, and presentation state.
3. Recover the selection path that chooses among named effects, then connect it
   to the player sanity value; the current map proves effect machinery but not the
   random-selection policy.
