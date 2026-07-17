# Subsystem and progress map

| Area | Evidence/status | Next milestone |
| --- | --- | --- |
| Disc/container | Redump-verified GEDE01 rev 0 | Re-run ingestion inside the permitted worktree |
| Executable | DOL sections and entry mapped | Generate committed DTK symbols/splits |
| Runtime modules | No REL/RSO evidence; DOL-only | Close after nested-archive review |
| PPCEABI runtime | Exception layout and key functions located | Split and match first runtime TU |
| Dolphin SDK | OS revision string and SDK signatures located | Classify signature matches by library/object |
| Debug/monitor | MetroTRK identified | Separate SDK/runtime progress category |
| Game engine | Unclassified | Seed subsystem names from strings/call graph |
| Rendering | Unclassified | Locate GX call clusters and frame loop |
| Audio | Unclassified | Locate AX/AI call clusters and music/SFX managers |
| Input | Unclassified | Locate PAD call clusters and controller state |
| World/scene | Unclassified | Locate scene transitions and entity update loops |
| Scripting/events | Unclassified | Identify opcode dispatch tables |
| Save/state | Unclassified | Locate CARD API call clusters and serialization |
| Sanity effects | Unclassified | Trace effect triggers from UI/render/audio dependencies |
| Assets/formats | 1,680 disc files inventoried, not typed | Produce extension/magic/type inventory without assets |
| Matching progress | 0 verified TUs | First 100% objdiff TU and unchanged DOL hash |
| Mod workflow | Designed, not boot-tested | Replace DOL in staged image and boot in Dolphin |

Generated objdiff progress supersedes this qualitative table once the initial DTK link order exists.

