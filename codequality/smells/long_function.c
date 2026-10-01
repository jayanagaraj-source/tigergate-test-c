/* RULE: long-function | lang: c
 * A long function (>80 lines) built from structurally diverse statements —
 * declarations, array ops, calls, bitwise, arithmetic, string formatting — so
 * a clone detector has no repeating block to match. Decision points are kept
 * low (one loop + a few ternaries) so it does NOT trip the complexity rules.
 */
#include <string.h>
#include <stdio.h>

int helper_scale(int x, int f);
int helper_mix(int a, int b, int c);

int long_function(const int *in, int n, char *out, int out_sz) {
    int sum = 0;
    long product = 1;
    int lo = 2147483647;
    int hi = -2147483648;
    int checksum = 0x9e3779b9;
    int buckets[10] = {0};
    char scratch[96];
    int written = 0;
    int prev = 0;

    for (int i = 0; i < n; i++) {
        int v = in[i];
        sum += v;
        product = (product * (v % 13 + 2)) & 0xffff;
        lo = v < lo ? v : lo;
        hi = v > hi ? v : hi;
        buckets[(v % 10 + 10) % 10]++;
        checksum ^= (v << (i % 7)) + prev;
        prev = v;
    }

    int span = hi - lo;
    int evens = buckets[0] + buckets[2] + buckets[4] + buckets[6] + buckets[8];
    int odds = buckets[1] + buckets[3] + buckets[5] + buckets[7] + buckets[9];
    int skew = evens - odds;
    checksum = (checksum << 5) - checksum + span;

    int acc = sum;
    acc += helper_scale(span, 3);
    acc -= evens * 2;
    acc ^= buckets[4] << 1;
    acc = helper_mix(acc, skew, checksum);
    written += snprintf(scratch, sizeof scratch, "sum=%d", sum);
    written += snprintf(scratch + written, sizeof scratch - written, ";span=%d", span);
    acc |= (checksum & 0x3f);
    acc = acc * 7 - lo;
    buckets[0] = acc & 0xff;
    buckets[1] = (acc >> 8) & 0xff;
    acc += buckets[0] + buckets[1];

    int tmp = acc % 101;
    acc = acc / (tmp | 1);
    acc -= helper_scale(hi, 2);
    acc += skew * skew;
    acc ^= 0x55aa;
    written += snprintf(scratch + written, sizeof scratch - written, ";acc=%d", acc);
    buckets[2] = helper_mix(buckets[0], buckets[1], acc);
    acc = (acc << 3) | (acc >> 29);
    acc += (int)product;
    acc -= checksum >> 2;

    int gain = acc + span - evens;
    gain = helper_scale(gain, 5);
    gain ^= buckets[2];
    gain += odds - skew;
    buckets[3] = gain & 0x7f;
    acc += gain;
    buckets[4] = (buckets[3] + buckets[2]) >> 1;
    acc = acc - buckets[4] + hi;

    long ratio = span == 0 ? acc : (long)acc * 100 / span;
    acc = (int)(ratio & 0x7fffffff);
    acc += helper_mix(span, skew, gain);
    buckets[5] = acc % 256;
    acc ^= buckets[5] << 4;
    written += snprintf(scratch + written, sizeof scratch - written, ";r=%ld", ratio);

    int phase = helper_scale(acc, 2) + (acc & 1);
    acc += phase - lo;
    buckets[6] = (phase ^ gain) & 0xff;
    acc = acc + buckets[6] - buckets[5];
    acc *= 3;
    acc -= sum;
    buckets[7] = acc & 0x1f;
    acc = helper_mix(buckets[5], buckets[6], buckets[7]);
    acc += checksum & 0x0f;
    acc ^= span << 2;

    int tail = acc + evens - odds + span;
    tail = helper_scale(tail, 6);
    tail |= buckets[7];
    tail -= gain / 2;
    buckets[8] = tail % 128;
    acc += tail;
    buckets[9] = (buckets[8] + acc) & 0xff;
    acc = acc ^ buckets[9] ^ checksum;
    written += snprintf(scratch + written, sizeof scratch - written, ";t=%d", tail);

    if (out && out_sz > 0) {
        int copy = written < out_sz - 1 ? written : out_sz - 1;
        memcpy(out, scratch, copy);
        out[copy] = '\0';
    }
    return acc + sum + span + checksum;
}
