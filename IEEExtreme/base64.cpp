#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <set>

static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  std::string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

#ifndef SHA256_H
#define SHA256_H
 
class SHA256
{
protected:
    typedef unsigned char uint8;
    typedef unsigned int uint32;
    typedef unsigned long long uint64;
 
    const static uint32 sha256_k[];
    static const unsigned int SHA224_256_BLOCK_SIZE = (512/8);
public:
    void init();
    void update(const unsigned char *message, unsigned int len);
    void final(unsigned char *digest);
    static const unsigned int DIGEST_SIZE = ( 256 / 8);
 
protected:
    void transform(const unsigned char *message, unsigned int block_nb);
    unsigned int m_tot_len;
    unsigned int m_len;
    unsigned char m_block[2*SHA224_256_BLOCK_SIZE];
    uint32 m_h[8];
};
 
std::string sha256(std::string input);
 
#define SHA2_SHFR(x, n)    (x >> n)
#define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define SHA2_ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z))
#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA256_F1(x) (SHA2_ROTR(x,  2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x, 22))
#define SHA256_F2(x) (SHA2_ROTR(x,  6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x, 25))
#define SHA256_F3(x) (SHA2_ROTR(x,  7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,  3))
#define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x, 10))
#define SHA2_UNPACK32(x, str)                 \
{                                             \
    *((str) + 3) = (uint8) ((x)      );       \
    *((str) + 2) = (uint8) ((x) >>  8);       \
    *((str) + 1) = (uint8) ((x) >> 16);       \
    *((str) + 0) = (uint8) ((x) >> 24);       \
}
#define SHA2_PACK32(str, x)                   \
{                                             \
    *(x) =   ((uint32) *((str) + 3)      )    \
           | ((uint32) *((str) + 2) <<  8)    \
           | ((uint32) *((str) + 1) << 16)    \
           | ((uint32) *((str) + 0) << 24);   \
}
#endif
 
const unsigned int SHA256::sha256_k[64] = //UL = uint32
            {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
             0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
             0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
             0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
             0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
             0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
             0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
             0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
             0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
             0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
             0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
             0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
             0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
             0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
             0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
             0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
 
void SHA256::transform(const unsigned char *message, unsigned int block_nb)
{
    uint32 w[64];
    uint32 wv[8];
    uint32 t1, t2;
    const unsigned char *sub_block;
    int i;
    int j;
    for (i = 0; i < (int) block_nb; i++) {
        sub_block = message + (i << 6);
        for (j = 0; j < 16; j++) {
            SHA2_PACK32(&sub_block[j << 2], &w[j]);
        }
        for (j = 16; j < 64; j++) {
            w[j] =  SHA256_F4(w[j -  2]) + w[j -  7] + SHA256_F3(w[j - 15]) + w[j - 16];
        }
        for (j = 0; j < 8; j++) {
            wv[j] = m_h[j];
        }
        for (j = 0; j < 64; j++) {
            t1 = wv[7] + SHA256_F2(wv[4]) + SHA2_CH(wv[4], wv[5], wv[6])
                + sha256_k[j] + w[j];
            t2 = SHA256_F1(wv[0]) + SHA2_MAJ(wv[0], wv[1], wv[2]);
            wv[7] = wv[6];
            wv[6] = wv[5];
            wv[5] = wv[4];
            wv[4] = wv[3] + t1;
            wv[3] = wv[2];
            wv[2] = wv[1];
            wv[1] = wv[0];
            wv[0] = t1 + t2;
        }
        for (j = 0; j < 8; j++) {
            m_h[j] += wv[j];
        }
    }
}
 
void SHA256::init()
{
    m_h[0] = 0x6a09e667;
    m_h[1] = 0xbb67ae85;
    m_h[2] = 0x3c6ef372;
    m_h[3] = 0xa54ff53a;
    m_h[4] = 0x510e527f;
    m_h[5] = 0x9b05688c;
    m_h[6] = 0x1f83d9ab;
    m_h[7] = 0x5be0cd19;
    m_len = 0;
    m_tot_len = 0;
}
 
void SHA256::update(const unsigned char *message, unsigned int len)
{
    unsigned int block_nb;
    unsigned int new_len, rem_len, tmp_len;
    const unsigned char *shifted_message;
    tmp_len = SHA224_256_BLOCK_SIZE - m_len;
    rem_len = len < tmp_len ? len : tmp_len;
    memcpy(&m_block[m_len], message, rem_len);
    if (m_len + len < SHA224_256_BLOCK_SIZE) {
        m_len += len;
        return;
    }
    new_len = len - rem_len;
    block_nb = new_len / SHA224_256_BLOCK_SIZE;
    shifted_message = message + rem_len;
    transform(m_block, 1);
    transform(shifted_message, block_nb);
    rem_len = new_len % SHA224_256_BLOCK_SIZE;
    memcpy(m_block, &shifted_message[block_nb << 6], rem_len);
    m_len = rem_len;
    m_tot_len += (block_nb + 1) << 6;
}
 
void SHA256::final(unsigned char *digest)
{
    unsigned int block_nb;
    unsigned int pm_len;
    unsigned int len_b;
    int i;
    block_nb = (1 + ((SHA224_256_BLOCK_SIZE - 9)
                     < (m_len % SHA224_256_BLOCK_SIZE)));
    len_b = (m_tot_len + m_len) << 3;
    pm_len = block_nb << 6;
    memset(m_block + m_len, 0, pm_len - m_len);
    m_block[m_len] = 0x80;
    SHA2_UNPACK32(len_b, m_block + pm_len - 4);
    transform(m_block, block_nb);
    for (i = 0 ; i < 8; i++) {
        SHA2_UNPACK32(m_h[i], &digest[i << 2]);
    }
}
 
std::string sha256(std::string input)
{
    unsigned char digest[SHA256::DIGEST_SIZE];
    memset(digest,0,SHA256::DIGEST_SIZE);
 
    SHA256 ctx = SHA256();
    ctx.init();
    ctx.update( (unsigned char*)input.c_str(), input.length());
    ctx.final(digest);

    return base64_encode(digest, SHA256::DIGEST_SIZE);
}

// using std::set;
// using std::string;
// using std::cout;
// using std::endl;
using namespace std;
ofstream fout("result.txt", ios::app);

int main(int argc, char *argv[])
{
	string strs[100] = {"/PtjJboZGlsmTovvyOhBOoTVnQKUP/gJXxjLAW9Lppw=",
"05HwH93tksb69U1ifesCQuYFP+gKPVH2L6W8JeBdXy0=",
"0BkyqI3NHyjh0m20wNt6txW08dglSMP4/qzUEezq4Aw=",
"1mT5cdKRz4BbfMdc8LAdnxfjsGO4lV0k0/V1IHtidmY=",
"28AdfW0JHmCP4TbieGON8dafRaFpUgpzuX2bHZN6WsM=",
"3hoie8omUyvM/9Qfx9dKfoptlwemYe2os8aohTGzoyw=",
"3uDaglIdYUn11AadEhELBjE15A0L6hAaWnZmjCGtt+M=",
"4D4NstIYSjVN826Q+SXUDDmXglJplpYWiJYf9rt7H8U=",
"7FCsEXCDTAxyLh3EPnNx7YrJ44SzehQYv3GmPSA6pWk=",
"81X3NN5JgTuGgqq3ErF0eL/l/wZFYkCwur6fZ06L2Us=",
"8FzGA/nS7XizLrAVOr/FoeKSq4gaoQRq+kpBKNXHIzc=",
"8OtpJ+E1XHv2RDsKIEwJc9KUFwPRzaqeHJ735Er6AVE=",
"8cdgZu9dBOrcTBMqElM+y9Vh5FTBRQ7n9EGa/4qVHUk=",
"8esDbw8ZVmUuUMEy2Scf5qGiZYiykevrvKpq2bVYHj4=",
"9DS4orbhPFbjJcosEqQg+eg0Si5qSOnftfHiqK8sYug=",
"9XDFIu4RPH0EL5XR+5VYILJ3UFAyltpfjONJKp/vcLk=",
"B2E/K/DywbLEKutOKpS8HxHFrZwucwac4KjzYgsXg3g=",
"BJQeqlV+4ejv0je5GpekzGdHHWHL5nnrbtD/170LZCA=",
"BjQiH/A2FUNHlUwhBi8NWmj3HmhmAh6Ag0kRyVSaVo8=",
"BwbAsOqPsxteVCpAwIjrhYogsUS1bF/bLns2QdcLYUI=",
"CYDZabjeyTAwcEDEcvrX83514UmpjzvQUQ68DIZ/PXg=",
"CornANxoZ5FJnlhwHmK42CDXf3h6jFr3g73YIRuoymQ=",
"DDa2TJX20pPsNftfyJ3s6LBwSMSR3EADZGDxW2wThbs=",
"FFXy3vru2D8rTWZRlh9lSMvtEusfWgO17OmJCTQTECs=",
"FGkqFC/jLDqDZ10fql1nGw7AQNWioOrZ3ydEaJyXBwo=",
"Fz+Y0H/R2rMZlc1C88Yx0A0xluYnVTinlw5qaSx8vWQ=",
"GcJMWMDF6+f+onf6oi1FbpnN7dVrFEZnlXtHqmaygs4=",
"GsXTQM0w+Clb1c9B7n28mADU2quLeI1n91KTyBboeHI=",
"HLnuqQmCYetzrau3frCDEpZ52QCIby108gugsmwAwQ0=",
"HWv9gx+GL/6g+0b0eOc+1Z/8BHse91/5T/DdiDwEknU=",
"IDB/pOthrWobzapJ/N8HsraNhwfbExAa2uusdiKHFFI=",
"IXYqlHbVeONERbxFe8SaEPEEKex45EihiC/l8CR52kk=",
"Idvs4Al9YZsqPG8xkSxVqb6MOVhbw5k+qtF8UZKYVE8=",
"IxQxcFXR51q8h8FLblPhYfUR30lIAt6hX8TjZWVa/GE=",
"JCmqBN0MsW13tEmsQPYWg9Fj25MUrqFYvSK2arxTt0A=",
"JOXxLH/i8i+fxDIWP2cts5Si/5En1A8M3s/vy6Aadic=",
"KudA8vCEQdGaaCSxotpAcluXnVPS3MAZPkwI/lVupak=",
"LGZEfbUr/tMREpJtsao/uuewcJXApmgfHDbh1zzfdhU=",
"LZIzmWEqXDPJsnKttFGRaG/jUhHrbTEKt1XCO6XbdME=",
"Lq0kV5M0HDSgB4m5KZbbn6BYRNlkKfaaAr3/11ueopY=",
"Lqxt1UjT1ecV6ucgYn+yrGSUTxPWkZgdDtbygGwC/BA=",
"MHQTB1MSsvhBxMpdRUiaM9Uj1QxU7zYq3FqDlW2HT2s=",
"MKewBZryb2l36Y0tDyx+WuVeXUGfiSzcJplm9y1w9m0=",
"N5aunKGHeN2WETLXLzfhfCxAfkwtGU/imziiTF3t7oY=",
"NmrOUzHxKSfNT8UJ1YXbRL8I+HCAb+glJ0bBXcHfagE=",
"NnSS+AuW1Z6zytSfqaiIVp4xxHHe70Av+IdhDlkoItQ=",
"O9L1ZWYwuzgaImTjOwuogXfpC+C44zzcDhpt08LjR5c=",
"R/ye+L9W+l6hyZ/v1POsWYboEGemIisARL8ohUvfBLI=",
"R1v9fEb9VrZuU5xiYTKTqhHF03VtXg7+KtfFHPkQuCQ=",
"RVfhsLovxa+/6tWgeSBASIIkzXkVtDPT4yYvjboHhIk=",
"Rz38Ng2qI3mPkaRB6uDoCYmmfzbVTCzpt2sG1o+TZqo=",
"S98FBzlv2vMVP/q+23m1wrHMJIrcy1rhoQGy338c4Bs=",
"SzraQWWasG5ZO1tJq16DqU/7M/o/WRiAWRl1aFFvwr8=",
"TInfNYwXvofBA+9QIe3+XEfDpO5ER+R+Jn3BOshhZWU=",
"VDkcRd54BhYlK5Wg2PPDa/jzGrSkMepGIv6Tw3I2ksc=",
"VjFTqTEY27V8lK2yCvhLhYm2Brh9bN1vWckVaevsiiY=",
"Wau4ReopjFKk8SYYNq5lIBL+Rgg8aBR6h9UgTIv2u7I=",
"XtEWsXf16y6Bc7vQxDy7hwRdBVWo3dV9C6CDVSf4PLs=",
"Y5b6UztMueFYIFMl4a61jlD/ZhFG74/rVn8XaqqU+8c=",
"YollqBlewcxE/kF6PKvv0r1CLZkKx82657bB0eQbiK0=",
"YzSqlQTtq5j+Kd+hW1ISgBW0mn61vsQsxNeipq0sYCo=",
"aJIH+q0YjYZCpierKtbue5JDtZSF8tKxVKuHYUPQ65k=",
"bi6rh2HgTbJxR2GOTNWZLlxiiWZVnObptGj0KqOCSYo=",
"cX7VyMvSYhuRvEfAUb3uNh8kmjpNFg0tatUPN562iOg=",
"eSCTiCrzHPbngPu3F4ivPkLUv7MqLUlmWAhA4UO975Y=",
"eUqkcVCbgIx1bGhhmnN5MxJFJhVruINmG65TjT/EQ1k=",
"gE7PseB3mspPtYG3JROzT9FeqTfPFYQvBF2SJD9V19Y=",
"gMi4hC4o7Fmv6yIrU48BVy8I1khXwkaD36G7bWiZHeo=",
"h84yifAWGLj9sakEqxZ3QEjkXL42AoScP3L5Tdevm98=",
"hEGKCiTZSA5x560hodRoIBBTE8pv4sP1VXG4D0fXWcI=",
"ix+0IJIpLpHeSHEII+Q/IVY+FlRXn3xMA0ey6UITi34=",
"j2GTUqtqZpotY8wF16zkvnbdCLTnX3oOZ30SjQUnIUk=",
"jtUg00EsmzzFkk8JgKg3OpkmPRpN9xbwsdNXQSPczwo=",
"k1J9Dv3EI442CO6A2FGN1H8JgFO2kjNBvkjDR0WIvkA=",
"kuRpkIh9kaNz6XvG8U6GO/IARH/SqhRnTiJbZHXC0yQ=",
"lFgqRrqTz1WXmO22u+Is1ZmWWUtuYrTJigsSB7I9NHI=",
"lUfxHX9xH2aOHheMMqQF+f5BNh97avew2uOwEN3B7HE=",
"m0IeuugWDOl9cFUFRYJhouCBT39T0dpp1xBOKPqHP94=",
"mgA5kgALstQpGUBp4vZ8oiz0P4jjAGl0wjgls6kQyMA=",
"nMAwaDYvEIAwoqtqWMpBAWdhuRgRq/fmwWbRM7cOMIU=",
"opBtoC66YDRbLNqZAAu2FIeKfF0HMOGHCOCPYeNHdx4=",
"ot/igM+me4e3UTT731qcBkSAcToyADMCddr7i7LCWGo=",
"qrkd/8imuRtiDb9N1w2hQRxJAkdx3Wqh1HVXPS7dym8=",
"r6BN0tdyAYZD0Nmc7bfV0WRcFBb1A2WIPPKHVRG59k8=",
"rdALvOYVhA3hnUTBlaQXigWBSgMYzGTreSKyMoAoKfw=",
"rjwtKqkPc7cfQ+zZ+E9c+fzQYhRvhVtaKEFb+srIHcQ=",
"rwvmTDiJxIEETbsngvpxYGwZZK+FGo7527odGuQUjtQ=",
"socJeO02bT2w+XZUrLoopbZvQ1lRhDfE88GVrJQ8p+g=",
"tDdmKQpMiVDFA1YdblkHSFzL4Z9UIQ9FSouf3TybOu0=",
"tojYiNtlWmq+7r1dSvxDk3W5at/NMAi1uxCHY61WAKk=",
"tqpGCBzhR+0ONFk1sBiHPhz+kRiXmY3CGdUXqnMJwLg=",
"uAZthS7b4ySZtWpM9pJ7ulYnhFdpFABpR2iPRQEmff0=",
"uCG9dSBejCOrZWsX7+u8G340p74s8lDS/El8MIeOyMo=",
"ugcIIpDID0R1uFqBAcN3PNXhwlhen77GdAccFgpbs+A=",
"usg8BTtSfewL5M3OVg91TJCTc5vONLqgUCC/Si1Grsg=",
"vs2sCU8qG0pDYQfcjlPzDzvcbJnhP1OgFRcXP4i3ffw=",
"wEtqAs8JHjicWnXshAWF5Sg6NoswuG9qeJ7USw7YD7c=",
"y+zbMpySKY+WF97KkgRQ+tBpM7iTqTj9guWmGJcqfyA=",
"y1R6JQiUzUovgtdrvCkbeQAyMhFoupzhI5ZuQVPfCgw=",
"zqKPAOt5ziHSeRxc0TgUZF3rJxzBHAKdJeccvt3F7Jg="};
	set<string> target;
	for(int i = 0; i < 100; ++i)
		target.insert(strs[i]);

	// char cs[] = {"qwertyuiopasdfghjklzxcvbnm1234567890*"};
	// string password;
	// int num[30] = {};
	// for(int i = 1, j; i < 20; ++i){
	// 	printf("i:%d\n", i);
	// 	password = "IEEE";
	// 	for(j = 0; j < i; ++j){
	// 		password+=cs[0];
	// 		num[j] = 0;
	// 	}
	// 	// password+="passwordq";
	// 	password+="Xtreme";
	// 	while(true){
	// 		++num[i-1];
	// 		password[4+i-1]=cs[num[i-1]];
	// 		for(j = i-1; j >= 0 && num[j] == 36; --j){
	// 			num[j] = 0;
	// 			password[4+j]=cs[0];
	// 			++num[j-1];
	// 			password[4+j-1]=cs[num[j-1]];
	// 		}
	// 		if(j == -1)
	// 			break;
	// 		// cout << password << '\n';
	// 		set<string>::iterator it = target.find(sha256(password));
	// 		if(it != target.end()){
	// 			cout << *it << '\t' << password << '\n';
	// 			fout << *it << '\t' << password << endl;
	// 		}
	// 	}

	// }	
    string input = "http://www.114w.com/p-567233-1.html";
    string output1 = sha256(input);
    printf("%s\n", output1.c_str());
 	set<string>::iterator it = target.find(output1);
 	if(it != target.end())
 		cout << *it;
 	else
 		printf("wrong\n");
    // cout << "sha256('"<< input << "'):" << output1 << endl;
    return 0;
}