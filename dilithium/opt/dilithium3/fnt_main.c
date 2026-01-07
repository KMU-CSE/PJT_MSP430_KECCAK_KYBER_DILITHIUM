
#include <stdio.h>
#include <stdint.h>
#include "polyvec.h"
#include "fnt_main.h"


//
////static const int32_t twiddles_intt_257_streamlined[] = { -19, 47, -69, 76, 119, -105, 94, 38, 104, -122, 26, 98, 22, -95, -30, 56, -125, 14, 33, 28, 66, 7, -112, 52, -61, 13, 49, -123, -88, -34, 96, 6, 24, -127, 48, 3, 12, 65, -36, 62, -9, -113, 11, 81, 121, -53, 77, 51, -45, 102, -90, -103, 106, -18, 31, 124, 72, 67, -44, 120, 80, 5, 20, -63, 40, -126, 10, 97, -25, -114, 58, 100, 111, 23, -15, -87, 107, -86, 91, 85, -75, -43, -83, 116, -57, 29, 50, 92, 70, -17, -39, 110, -74, -101, 109, 55, -37, 78, -21, 79, 59, 84, -73, -117, -68, -115, 41, -93, -54, 71, -108, 82, -27, 118, -89, -99, 42, 46, 35, 60 };
//int16_t twiddles_basemul_257[] = { 27, -82, 108, -71, 54, 93, -41, 115, -78, 37, -55, -109, 101, 74, -110, 39, 83, 43, 75, -85, -91, 86, -107, 87, -97, -10, 126, -40, 63, -20, -5, -80, -106, 103, 90, -102, 45, -51, -77, 53, -65, -12, -3, -48, 127, -24, -6, -96, 112, -7, -66, -28, -33, -14, 125, -56, -38, -94, 105, -119, -76, 69, -47, 19 };
//
///*unity = 7*/
////int16_t fnt769_zeta[] = { 1, 62, 40, -83, 121, 27, -56, 55, 121, 48, -43, 113, -5, -74, 43, 103, 94, -67, -84, 113, 33, -25, 25, 12, 64, 123, -3, 50, 12, -66, -59, -89, 49, -37, -90, 18, 1, 42, 27, 116, 17, 29, -88, 122, -4, -53, 57, -95, -7, 17, -63, -102, 63, 41, -56, 76, 60, -124, 93, 127, 43, 82, -87, -52, 7, -78, 24, -70, 74, -67, 114, 127, 76, 78, -49, 18, -37, -7, 45, -50, -110, 39, -82, 22, -27, 79, -81, 84, -64, 92, -23, 92, 80, 49, 98, -117, 87, -9, -121, 126, 5, 33, -69, 39, 119, -55, -110, 81, -34, -119, -118, 97, -55, 117, 67, 53, -73, 26, 116, 15, -92, -105, -117, 118, 43, 62, -100, -109 };
///*unity = 49*/
////int16_t fnt769_zeta[] = { 1, 0, 62, -61, 40, -39, -83, 84, 121, -120, 27, -26, -56, 57, 55, -54, 121, -120, 48, -47, -43, 44, 113, -112, -5, 6, -74, 75, 43, -42, 103, -102, 94, -93, -67, 68, -84, 85, 113, -112, 33, -32, -25, 26, 25, -24, 12, -11, 64, -63, 123, -122, -3, 4, 50, -49, 12, -11, -66, 67, -59, 60, -89, 90, 49, -48, -37, 38, -90, 91, 18, -17, 1, 0, 42, -41, 27, -26, 116, -115, 17, -16, 29, -28, -88, 89, 122, -121, -4, 5, -53, 54, 57, -56, -95, 96, -7, 8, 17, -16, -63, 64, -102, 103, 63, -62, 41, -40, -56, 57, 76, -75, 60, -59, -124, 125, 93, -92, 127, -126, 43, -42, 82, -81, -87, 88, -52, 53 };
//
//int16_t fnt769_zeta[] = { 0, 62, 40, 173, -136, 27, -57, 311, 377, 304, -300, -144, 251, 182, 43, 359, 94, -324, -85, 113, 289, 231, 25, 12, 64, 123, 253, 306, -245, 190, 197, -90, 49, -38, -347, 18, 257, -215, 283, -141, 17, 285, -89, -135, -5, -310, -200, -96, -8, 273, -320, 154, 319, -216, -313, -181, 60, -125, 93, 383, 299, 82, -344, 204, 7, -335, 280, -327, -183, 189, 370, -130, 332, -179, 207, -239, 219, -264, 301, 206, -111, 39, 174, 22, -284, 79, 175, 84, -321, 92, 233, -165, -177, -208, -159, 139, 343, -266, -122, 126, 261, 33, -326, -218, 119, -312, 146, -176, -35, 137, 138, 97, -56, 373, 67, 309, -74, 26, 116, 271, -349, -106, -118, 374, -214, -195, -101, -110 };
//
//#define FNT_CT_butterfly(c0, c1, logW) \
//		c0 = (c0+(((c1)<<(logW)))); \
//		c1 = (c0-(((c1)<<(logW)))); \
//
//#define SMALL_Q 769
//#define SMALL_Q_PRIME (16711935)
//
//int32_t barrett_reduce_fnt(int64_t a) {
//	int64_t t;
//
//	t = ((int64_t)SMALL_Q_PRIME * a + ((int64_t)0x01 << 31)) >> 32;	
//	t *= SMALL_Q;
//	return a - t;
//}
//
//void forward_fnt(int32_t poly[256])
//{
//	unsigned int len, start, j, k;
//	int64_t t, zeta;
//	
//
//	k = 0;
//
//	// first 3-layers
//	for (len = 128; len >= 32; len >>= 1) { //len >=32
//		for (start = 0; start < 256; start = j + len) {
//			//zeta = twiddles_ntt_257_normal_order[++k];
//			zeta = fnt769_zeta[++k];
//			for (j = start; j < start + len; ++j) {
//				t = (zeta * (int64_t)poly[j + len]);                
//				t = t % SMALL_Q;
//				poly[j + len] = poly[j] - t;
//				poly[j] = poly[j] + t;
//			}
//		}
//	} 
//        
//
//	// remaining 4-layers
//	for (; len >= 2; len >>= 1) {
//		for (start = 0; start < 256; start = j + len) {
//			zeta = fnt769_zeta[++k];
//			for (j = start; j < start + len; ++j) {
//				t = (zeta * (int64_t)poly[j + len]);				
//				t = t % SMALL_Q;
//				poly[j + len] = poly[j] - t;
//				poly[j] = poly[j] + t;
//			}
//		}
//		
//	}
//    
//	for (int i = 0; i < 256; i++) {
//		poly[i] %= SMALL_Q;
//		if (poly[i] > SMALL_Q / 2)
//			poly[i] -= SMALL_Q;
//		if (poly[i] < -SMALL_Q / 2)
//			poly[i] += SMALL_Q;
//	}
//
//    return;
//}
//
//void reverse_fnt(int32_t poly[256])
//{
//	unsigned int len, start, j, k;
//	int64_t t, zeta;
//	
//
//	//const int16_t f = 255;
//	const int16_t f = 763;
//	
//
//	k = 127;
//
//	for (len = 2; len <= 128; len <<= 1) {
//		for (start = 0; start < 256; start = j + len) {
//			zeta = fnt769_zeta[k--];
//			for (j = start; j < start + len; j++) {
//				t = poly[j];
//				poly[j] = t + poly[j + len];
//				poly[j + len] = poly[j + len] - t;
//				//poly[j + len] = barrett_reduce_fnt((int64_t)zeta * poly[j + len]);
//				poly[j + len] = ((int64_t)zeta * poly[j + len]) % 769;
//			}
//		}
//                               
//	}
//        
//        
//
//	for (int i = 0; i < 256; i++) {
//		//poly[i] = barrett_reduce_fnt(poly[i] * f);
//		poly[i] = (poly[i] * f) % 769;
//		if (poly[i] > 769 / 2)
//			poly[i] -= 769;
//		if (poly[i] < -769 / 2)
//			poly[i] += 769;
//	}
//}
//
//void pointwise(int32_t ret[256], int32_t poly1[256], int32_t poly2[256])
//{
//        
////	int cnt = 0;
////	for (int i = 0; i < 256; i += 4) {
////		ret[i] = poly1[i + 1] * poly2[i + 1];
////		ret[i] = ret[i] * twiddles_basemul_257[cnt];
////		ret[i] += poly1[i] * poly2[i];
////
////		ret[i + 1] = poly1[i + 1] * poly2[i];
////		ret[i + 1] += poly1[i] * poly2[i + 1];
////
////		ret[i + 2] = poly1[i + 3] * poly2[i + 3];
////		ret[i + 2] = ret[i + 2] * -twiddles_basemul_257[cnt];
////		ret[i + 2] += poly1[i + 2] * poly2[i + 2];
////
////		ret[i + 3] = poly1[i + 3] * poly2[i + 2];
////		ret[i + 3] += poly1[i + 2] * poly2[i + 3];
////
////		cnt++;
////	}
//
//        
//    int32_t temp_fnt[4] = {0,};
//	int cnt = 0;
//        
//	for (int i = 0; i < 256; i += 4) {
//		temp_fnt[0] = poly1[i + 1] * poly2[i + 1];
//		temp_fnt[0] = temp_fnt[0] * twiddles_basemul_257[cnt];
//		temp_fnt[0] += poly1[i] * poly2[i];
//
//		temp_fnt[1] = poly1[i + 1] * poly2[i];
//		temp_fnt[1] += poly1[i] * poly2[i + 1];
//
//		temp_fnt[2] = poly1[i + 3] * poly2[i + 3];
//		temp_fnt[2] = temp_fnt[2] * -twiddles_basemul_257[cnt];
//		temp_fnt[2] += poly1[i + 2] * poly2[i + 2];
//
//		temp_fnt[3] = poly1[i + 3] * poly2[i + 2];
//		temp_fnt[3] += poly1[i + 2] * poly2[i + 3];
//
//		ret[i] = temp_fnt[0];
//                ret[i+1] = temp_fnt[1];
//                ret[i+2] = temp_fnt[2];
//                ret[i+3] = temp_fnt[3];
//                cnt++;
//	}
//
//	for (int i = 0; i < 256; i++) {
//		ret[i] = barrett_reduce_fnt(ret[i]);
//	}
//
//}

int16_t FNT_Q2_zetas[128] = { 0, -164, -81, 361, -186, 3, 250, 120, -129, -308, 223, -16, -143, 362, -337, -131, -75, -36, 76, 98, 203, 282, -339, -255, 178, 270, 199, 34, -369, 192, -149, -10, -80, -346, -124, 2, 114, 147, -54, -272, -169, 288, 161, -15, -86, 51, -364, -267, 170, -226, -121, 188, -50, -24, 307, -191, 263, 157, -246, 128, 375, 180, -380, 279, -341, -379, 202, 220, 236, 21, 212, 71, -134, 151, 23, -112, -232, 227, -52, -148, 244, -252, -237, -83, -117, -333, -66, -247, -292, 352, -145, 238, -276, -194, -274, -70, 209, -115, -99, 14, 29, 260, -378, -366, 355, -291, 358, -105, 167, 357, -241, -331, -348, -44, -78, -222, -350, -168, -158, 201, 303, 330, -184, 127, 318, -278, -353, -354 };
int16_t FNT_Q2_zetas_asm[128] = { -129, -75, -36, -308, 76, 98, 223, 203, 282, -16, -339, -255, -143, 178, 270, 362, 199, 34, -337, -369, 192, -131, -149, -10, -80, -341, -379, -346, 202, 220, -124, 236, 21, 2, 212, 71, 114, -134, 151, 147, 23, -112, -54, -232, 227, -272, -52, -148, -169, 244, -252, 288, -237, -83, 161, -117, -333, -15, -66, -247, -86, -292, 352, 51, -145, 238, -364, -276, -194, -267, -274, -70, 170, 209, -115, -226, -99, 14, -121, 29, 260, 188, -378, -366, -50, 355, -291, -24, 358, -105, 307, 167, 357, -191, -241, -331, 263, -348, -44, 157, -78, -222, -246, -350, -168, 128, -158, 201, 375, 303, 330, 180, -184, 127, -380, 318, -278, 279, -353, -354 };

static int ct_lt_s32(uint32_t x, uint32_t y) { return (x ^ ((x ^ (x - y)) & (y ^ (x - y)))) >> 31; }
static int ct_gt_s32(uint32_t x, uint32_t y) { return ct_lt_s32(y, x); }

#define FNT_Q2HF (769 / 2)
#define FNT_Q2HFNEG -(769 / 2)
#define FNT_Q2 769
#define QinvR (-767)

//int32_t fnt_freeze(int32_t src)
//{
//    int32_t r = src;
//    uint16_t mask;
//
//    mask = 0 - ct_gt_s32(src, FNT_Q2HF); // if (src > FNT_Q2HF) r -= 769;
//    r -= mask & 769;
//    mask = 0 - ct_lt_s32(src, (uint32_t)FNT_Q2HFNEG); // if (src < -FNT_Q2HF) r += 769;
//    r += mask & 769;
//    return r;
//}
//
//static int16_t fnt769_montgomery_reduce(int32_t a)
//{
//    int16_t t;
//
//    t = (int16_t)a * QinvR;
//    t = (a - (int32_t)t * FNT_Q2) >> 16;
//    return t;
//}
//
//void fnt_ntt(int32_t r[256])
//{
//    unsigned int len, start, j, k;
//    int16_t t, zeta;
//
//    k = 1;
//    for (len = 128; len >= 2; len >>= 1) {
//        for (start = 0; start < 256; start = j + len) {
//            zeta = FNT_Q2_zetas[k++];
//            for (j = start; j < start + len; j++)
//            {
//                t = fnt769_montgomery_reduce((int32_t)zeta * r[j + len]);
//                r[j + len] = (r[j] - t);
//                r[j] = (r[j] + t);
//            }
//        }               
//    }
//}
//
//void fnt_invntt(int32_t r[256])
//{
//    unsigned int start, len, j, k;
//    int16_t t, zeta;
//    const int16_t f = 655; // (1 << 16)^2 / 128
//
//    k = 127;
//    for (len = 2; len <= 128; len <<= 1) {
//        for (start = 0; start < 256; start = j + len)
//        {
//            //if (len == 128) zeta = FNT_Q2_zetas[0];
//            //else zeta = FNT_Q2_zetas[k--];
//            zeta = FNT_Q2_zetas[k--];
//            for (j = start; j < start + len; j++)
//            {
//                t = r[j];
//                r[j] = (t + r[j + len]);
//                r[j + len] = (r[j + len] - t);
//                r[j + len] = fnt769_montgomery_reduce((int32_t)zeta * r[j + len]);
//            }
//        }
//        
//        
//    }        
//    
//    for (int cnt_i = 0; cnt_i < 256; cnt_i++)
//    {
//        r[cnt_i] = fnt769_montgomery_reduce((int32_t)r[cnt_i] * f);     
//    }
//}
//
//
//void fnt769_basemul(int32_t r[2], const int32_t a[2], const int32_t b[2], int16_t zeta)
//{
//    int32_t tmp[2] = { 0 };
//
//    tmp[0] = (int32_t)fnt769_montgomery_reduce(a[1] * b[1]);
//    tmp[0] = (int32_t)fnt769_montgomery_reduce(tmp[0] * zeta);
//    tmp[0] += (int32_t)fnt769_montgomery_reduce(a[0] * b[0]);
//    tmp[1] = (int32_t)fnt769_montgomery_reduce(a[0] * b[1]);
//    tmp[1] += (int32_t)fnt769_montgomery_reduce(a[1] * b[0]);
//
//    r[0] = tmp[0]; r[1] = tmp[1];
//}
//
//void point_mul_small(int32_t des[N], int32_t src1[N], int32_t src2[N])
//{
//    for (int cnt_i = 0; cnt_i < N / 4; cnt_i++)
//    {
//        fnt769_basemul(&des[4 * cnt_i], &src1[4 * cnt_i], &src2[4 * cnt_i], FNT_Q2_zetas[64 + cnt_i]);
//        fnt769_basemul(&des[4 * cnt_i + 2], &src1[4 * cnt_i + 2], &src2[4 * cnt_i + 2], -FNT_Q2_zetas[64 + cnt_i]);
//    }
//}











void poly_fnt(poly* a) {
    //fnt_ntt(a->coeffs);
	//forward_fnt(a->coeffs);
    asm_fnt_merging(a->coeffs, &FNT_Q2_zetas_asm[0]);
}

void poly_invfnt(poly* a) {
    //fnt_invntt(a->coeffs);
	//reverse_fnt(a->coeffs);
    asm_invfnt_merging(a->coeffs, &FNT_Q2_zetas_asm[119]);
}

void poly_pointwise_fnt(poly* r, poly* a, poly* b) {
  //point_mul_small(r->coeffs, a->coeffs, b->coeffs);
	//pointwise(r->coeffs, a->coeffs, b->coeffs);
    asm_pointwise_fnt(r->coeffs, a->coeffs, b->coeffs, &FNT_Q2_zetas[64]);
}

