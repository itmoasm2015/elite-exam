
#define CMD_ADD_LEFT 3
#define CMD_ADD_RIGHT 7
#define CMD_CMP 4
#define CMD_NEG 1
#define CMD_ADD 0
#define CMD_HOAX1 5
#define CMD_HOAX2 6
#define CMD_NOP 2



int check(unsigned char const *s, int length) {
    if (!s) {
        return 0;
    }

    int proglen = length >> 1;
    int datalen = length - proglen;
    if (datalen == 0)
        return 0;
    unsigned char const *data = s + proglen;

    int dataIndex = 0;
    int sum = 3538;
    volatile int hoax = 4;
    for (int i = 0; i < (proglen << 1); ++i) {
        int cmd = (s[i >> 1] >> ((i & 1) ? 0 : 4)) & 0x0f;
        switch (cmd) {
        case CMD_ADD_LEFT:
            sum += data[dataIndex];
            dataIndex -= 1;
            if (dataIndex < 0)
                return 0;
            break;
        case CMD_ADD_RIGHT:
            sum += data[dataIndex];
            dataIndex += 1;
            if (dataIndex >= datalen)
                return 0;
            break;
        case CMD_CMP:
            if (sum != data[dataIndex])
                return 0;
            break;
        case CMD_NEG:
            sum = -sum;
            break;
        case CMD_ADD:
            sum += data[dataIndex];
            break;
        case CMD_NOP:
            break;
        case CMD_HOAX1:
            if (hoax & 1)
                return 0;
            break;
        case CMD_HOAX2:
            hoax += sum << 1;
            break;
        default:
            return 0;
        }
    }

    return sum == -239;
}
