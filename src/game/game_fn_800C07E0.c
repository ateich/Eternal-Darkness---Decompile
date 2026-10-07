/* fn_800C07E0: looks up a result code from the object's type, a sub-type
 * and a kind (1..3). Sub-types come in groups of seven (base+0..base+6).
 * Returns -1 when the combination has no entry. */

extern int fn_8011EB04(void *);

int fn_800C07E0(void *object, int kind, int sub) {
    int result = -1;

    switch (fn_8011EB04(object)) {
    case 0x4C:
        switch (sub) {
        case 0x00: case 0x07: case 0x0E: case 0x69:
            switch (kind) {
            case 2: result = 0x0C; break;
            case 3: result = 0x11; break;
            case 1: result = 0x25; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09:
        case 0x0F: case 0x10: case 0x6A: case 0x6B:
            switch (kind) {
            case 2: result = 0x13; break;
            case 3: result = 0x12; break;
            case 1: result = 0x25; break;
            }
            break;
        case 0x05: case 0x0C: case 0x13: case 0x6E:
            switch (kind) {
            case 2: result = 0x0C; break;
            case 3: result = 0x17; break;
            case 1: result = 0x25; break;
            }
            break;
        case 0x04: case 0x0B: case 0x12: case 0x6D:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x11; break;
            case 1: result = 0x25; break;
            }
            break;
        }
        break;
    case 0x12:
        switch (sub) {
        case 0x00: case 0x0E: case 0x3F: case 0x77:
            switch (kind) {
            case 2: result = 0x0C; break;
            case 3: result = 0x11; break;
            case 1: result = 0x25; break;
            }
            break;
        case 0x01: case 0x02: case 0x0F: case 0x10:
        case 0x40: case 0x41: case 0x78: case 0x79:
            switch (kind) {
            case 2: result = 0x13; break;
            case 3: result = 0x12; break;
            case 1: result = 0x25; break;
            }
            break;
        case 0x05: case 0x13: case 0x44: case 0x7C:
            switch (kind) {
            case 2: result = 0x0C; break;
            case 3: result = 0x17; break;
            case 1: result = 0x25; break;
            }
            break;
        case 0x04: case 0x12: case 0x43: case 0x7B:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x11; break;
            case 1: result = 0x25; break;
            }
            break;
        }
        break;
    case 0x96:
        switch (sub) {
        case 0x00: case 0x07: case 0x0E: case 0x2A: case 0x3F: case 0x77:
            switch (kind) {
            case 2: result = 0x16; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09: case 0x0F: case 0x10:
        case 0x2B: case 0x2C: case 0x40: case 0x41: case 0x78: case 0x79:
            switch (kind) {
            case 2: result = 0x0F; break;
            case 3: result = 0x11; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x04: case 0x0B: case 0x12: case 0x2E: case 0x43: case 0x7B:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x0C: case 0x13: case 0x2F: case 0x44: case 0x7C:
            switch (kind) {
            case 2: result = 0x16; break;
            case 3: result = 0x14; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x00:
        switch (sub) {
        case 0x00: case 0x04: case 0x0E: case 0x12:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x16; break;
            case 1: result = 0x1B; break;
            }
            break;
        case 0x01: case 0x02: case 0x0F: case 0x10:
            switch (kind) {
            case 2: result = 0x0F; break;
            case 3: result = 0x0C; break;
            case 1: result = 0x1B; break;
            }
            break;
        case 0x05: case 0x13:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x13; break;
            case 1: result = 0x1B; break;
            }
            break;
        }
        break;
    case 0x65:
    case 0x7A:
        switch (sub) {
        case 0x00: case 0x01: case 0x02: case 0x04: case 0x05:
        case 0x07: case 0x08: case 0x09: case 0x0B: case 0x0C:
        case 0x0E: case 0x0F: case 0x10: case 0x12: case 0x13:
        case 0x2A: case 0x2B: case 0x2C: case 0x2E: case 0x2F:
            switch (kind) {
            case 2: result = 0x0E; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x0E; break;
            }
            break;
        }
        break;
    case 0x78:
    case 0x79:
        switch (sub) {
        case 0x00: case 0x01: case 0x02: case 0x07: case 0x08: case 0x09:
        case 0x0E: case 0x0F: case 0x10: case 0x2A: case 0x2B: case 0x2C:
            switch (kind) {
            case 2: result = 0x0D; break;
            case 3: result = 0x18; break;
            case 1: result = 0x18; break;
            }
            break;
        case 0x04: case 0x0B: case 0x12: case 0x2E:
            switch (kind) {
            case 2: result = 0x0F; break;
            case 3: result = 0x18; break;
            case 1: result = 0x18; break;
            }
            break;
        case 0x05: case 0x0C: case 0x13: case 0x2F:
            switch (kind) {
            case 2: result = 0x0D; break;
            case 3: result = 0x14; break;
            case 1: result = 0x14; break;
            }
            break;
        }
        break;
    case 0x55:
    case 0x77:
        switch (sub) {
        case 0x00: case 0x04: case 0x07: case 0x0B:
        case 0x0E: case 0x12: case 0x2A: case 0x2E:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x0F; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09:
        case 0x0F: case 0x10: case 0x2B: case 0x2C:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x1B; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x0C: case 0x13: case 0x2F:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x13; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x4B:
        switch (sub) {
        case 0x00: case 0x04: case 0x07: case 0x0B: case 0x0E:
        case 0x12: case 0x3F: case 0x43: case 0x4D: case 0x51:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x0F; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09: case 0x0F:
        case 0x10: case 0x40: case 0x41: case 0x4E: case 0x4F:
            switch (kind) {
            case 2: result = 0x18; break;
            case 3: result = 0x1B; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x0C: case 0x13: case 0x44: case 0x52:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x13; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x4A:
        switch (sub) {
        case 0x00: case 0x04: case 0x07: case 0x0B: case 0x0E:
        case 0x12: case 0x38: case 0x3C: case 0x69: case 0x6D:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x0F; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09: case 0x0F:
        case 0x10: case 0x39: case 0x3A: case 0x6A: case 0x6B:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x1B; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x0C: case 0x13: case 0x3D: case 0x6E:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x13; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x45:
        switch (sub) {
        case 0x00: case 0x04: case 0x0E: case 0x12: case 0x3F:
        case 0x43: case 0x4D: case 0x51: case 0x54: case 0x58:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x0F; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x13: case 0x44: case 0x52: case 0x59:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x13; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x0F: case 0x10: case 0x40:
        case 0x41: case 0x4E: case 0x4F: case 0x55: case 0x56:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x1B; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x49:
        switch (sub) {
        case 0x00: case 0x07: case 0x2A: case 0x3F: case 0x4D:
            switch (kind) {
            case 2: result = 0x16; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x04: case 0x0B: case 0x2E: case 0x43: case 0x51:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x0C: case 0x2F: case 0x44: case 0x52:
            switch (kind) {
            case 2: result = 0x16; break;
            case 3: result = 0x14; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09: case 0x2B:
        case 0x2C: case 0x40: case 0x41: case 0x4E: case 0x4F:
            switch (kind) {
            case 2: result = 0x0F; break;
            case 3: result = 0x11; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x51:
        switch (sub) {
        case 0x00: case 0x2A: case 0x3F: case 0x4D:
            switch (kind) {
            case 2: result = 0x16; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x05: case 0x2F: case 0x44: case 0x52:
            switch (kind) {
            case 2: result = 0x16; break;
            case 3: result = 0x14; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x01: case 0x02: case 0x2B: case 0x2C:
        case 0x40: case 0x41: case 0x4E: case 0x4F:
            switch (kind) {
            case 2: result = 0x0F; break;
            case 3: result = 0x11; break;
            case 1: result = 0x15; break;
            }
            break;
        case 0x04: case 0x2E: case 0x43: case 0x51:
            switch (kind) {
            case 2: result = 0x0B; break;
            case 3: result = 0x0E; break;
            case 1: result = 0x15; break;
            }
            break;
        }
        break;
    case 0x46:
        switch (sub) {
        case 0x00: case 0x05: case 0x0E: case 0x13: case 0x70: case 0x75:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x12; break;
            case 1: result = 0x14; break;
            }
            break;
        case 0x01: case 0x02: case 0x0F: case 0x10: case 0x71: case 0x72:
            switch (kind) {
            case 2: result = 0x0C; break;
            case 3: result = 0x0D; break;
            case 1: result = 0x14; break;
            }
            break;
        case 0x04: case 0x12: case 0x74:
            switch (kind) {
            case 2: result = 0x10; break;
            case 3: result = 0x12; break;
            case 1: result = 0x14; break;
            }
            break;
        }
        break;
    case 0x09:
        switch (sub) {
        case 0x05: case 0x0C: case 0x13: case 0x44: case 0x52:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x12; break;
            case 1: result = 0x14; break;
            }
            break;
        case 0x00: case 0x07: case 0x0E: case 0x3F: case 0x4D: case 0x77:
            switch (kind) {
            case 2: result = 0x02; break;
            case 3: result = 0x11; break;
            case 1: result = 0x14; break;
            }
            break;
        case 0x01: case 0x02: case 0x08: case 0x09: case 0x0F:
        case 0x10: case 0x40: case 0x41: case 0x4E: case 0x4F:
            switch (kind) {
            case 2: result = 0x0C; break;
            case 3: result = 0x0D; break;
            case 1: result = 0x14; break;
            }
            break;
        case 0x04: case 0x0B: case 0x12: case 0x43: case 0x51:
            switch (kind) {
            case 2: result = 0x10; break;
            case 3: result = 0x11; break;
            case 1: result = 0x14; break;
            }
            break;
        }
        break;
    }

    return result;
}
