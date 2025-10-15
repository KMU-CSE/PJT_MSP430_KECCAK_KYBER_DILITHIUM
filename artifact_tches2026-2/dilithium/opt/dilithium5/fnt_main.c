
#include <stdio.h>
#include <stdint.h>
#include "polyvec.h"
#include "fnt_main.h"


//int16_t twiddles_ntt_257_normal_order[] = { 0,
//														16,
//														4, 64,
//														2, 32, 8, 128,
//														-60, 68, 17, 15, -120, -121, 34, 30,
//														-35, -46, 117, 73, -70, -92, -23, -111, 44, -67, -81, -11, 88, 123, 95, -22,
//														-42, 99, 89, -118, -84, -59, -79, 21, -50, -29, 57, -116, -100, -58, 114, 25, -72, -124, -31, 18, 113, 9, -62, 36, -49, -13, 61, -52, -98, -26, 122, -104,
//														27, -82, 108, -71, 54, 93, -41, 115, -78, 37, -55, -109, 101, 74, -110, 39, 83, 43, 75, -85, -91, 86, -107, 87, -97, -10, 126, -40, 63, -20, -5, -80, -106, 103, 90, -102, 45,
//														-51, -77, 53, -65, -12, -3, -48, 127, -24, -6, -96, 112, -7, -66, -28, -33, -14, 125, -56, -38, -94, 105, -119, -76, 69, -47, 19
//};
//
//
//
//static const int32_t twiddles_intt_257_streamlined[] = { -19, 47, -69, 76, 119, -105, 94, 38, 104, -122, 26, 98, 22, -95, -30, 56, -125, 14, 33, 28, 66, 7, -112, 52, -61, 13, 49, -123, -88, -34, 96, 6, 24, -127, 48, 3, 12, 65, -36, 62, -9, -113, 11, 81, 121, -53, 77, 51, -45, 102, -90, -103, 106, -18, 31, 124, 72, 67, -44, 120, 80, 5, 20, -63, 40, -126, 10, 97, -25, -114, 58, 100, 111, 23, -15, -87, 107, -86, 91, 85, -75, -43, -83, 116, -57, 29, 50, 92, 70, -17, -39, 110, -74, -101, 109, 55, -37, 78, -21, 79, 59, 84, -73, -117, -68, -115, 41, -93, -54, 71, -108, 82, -27, 118, -89, -99, 42, 46, 35, 60 };
//
//#define FNT_CT_butterfly(c0, c1, logW) \
//		c0 = (c0+(((c1)<<(logW)))); \
//		c1 = (c0-(((c1)<<(logW)))); \

#define SMALL_Q 257
#define SMALL_Q_PRIME (16711935)

//int32_t barrett_reduce_fnt(int64_t a) {
//	int64_t t;
//        
//	t = ((int64_t)SMALL_Q_PRIME * a + ((int64_t)0x01 << 31)) >> 32;	
//	t *= SMALL_Q;
//	return a - t;
//}

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
//			zeta = twiddles_ntt_257_normal_order[++k];
//			for (j = start; j < start + len; ++j) {
//				t = (zeta * (int64_t)poly[j + len]);
//                                if(len == 32 && start >= 128)t = barrett_reduce_fnt(t);
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
//			zeta = twiddles_ntt_257_normal_order[++k];
//			for (j = start; j < start + len; ++j) {
//				t = (zeta * (int64_t)poly[j + len]);
//				t = barrett_reduce_fnt(t);
//				poly[j + len] = poly[j] - t;
//				poly[j] = poly[j] + t;
//			}
//		}
//		
//	}
//        
//        return;
//}

//void reverse_fnt(int32_t poly[256])
//{
//	unsigned int len, start, j, k;
//	int64_t t, zeta;
//	
//
//	const int16_t f = 255;
//
//	k = 127;
//
//	for (len = 2; len <= 128; len <<= 1) {
//		for (start = 0; start < 256; start = j + len) {
//			zeta = twiddles_ntt_257_normal_order[k--];
//			for (j = start; j < start + len; j++) {
//				t = poly[j];
//				poly[j] = t + poly[j + len];
//				poly[j + len] = poly[j + len] - t;
//				poly[j + len] = barrett_reduce_fnt((int64_t)zeta * poly[j + len]);				
//			}
//		}
//                
//	}
//        
//        
//
//	for (int i = 0; i < 256; i++) {
//		poly[i] = barrett_reduce_fnt(poly[i] * f);
//	}
//}
//
//void pointwise(int32_t ret[256], int32_t poly1[256], int32_t poly2[256])
//{             
//        int32_t temp_fnt[4] = {0,};
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

int16_t temp_twiddles[] =
{
  -60, -35, -46, 68, 117, 73, 17, -70, -92, 15, -23, -111, -120, 44, -67, -121, -81, -11, 34, 88, 123, 30, 95, -22,
  -42, 27, -82, 99, 108, -71, 89, 54, 93, -118, -41, 115, -84, -78, 37, -59, -55, -109, -79, 101, 74, 21, -110, 39, -50, 83, 43, -29, 75, -85, 57, -91, 86, -116, -107, 87, -100, -97, -10, -58, 126, -40, 114, 63, -20, 25, -5, -80, -72, -106, 103, -124, 90, -102, -31, 45, -51, 18, -77, 53, 113, -65, -12, 9, -3, -48, -62, 127, -24, 36, -6, -96, -49, 112, -7, -13, -66, -28, 61, -33, -14, -52, 125, -56, -98, -38, -94, -26, 105, -119, 122, -76, 69, -104, -47, 19
};                
int16_t twiddles_basemul_257[] = { 27, -82, 108, -71, 54, 93, -41, 115, -78, 37, -55, -109, 101, 74, -110, 39, 83, 43, 75, -85, -91, 86, -107, 87, -97, -10, 126, -40, 63, -20, -5, -80, -106, 103, 90, -102, 45, -51, -77, 53, -65, -12, -3, -48, 127, -24, -6, -96, 112, -7, -66, -28, -33, -14, 125, -56, -38, -94, 105, -119, -76, 69, -47, 19 };
                  
void poly_fnt(poly* a) {
	//forward_fnt(a->coeffs);
        asm_fnt_merging(a->coeffs, &temp_twiddles[0]);
}

void poly_invfnt(poly* a) {
	//reverse_fnt(a->coeffs);
        asm_invfnt_merging(a->coeffs, &temp_twiddles[119]);
}

void poly_pointwise_fnt(poly* r, poly* a, poly* b) {
	//pointwise(r->coeffs, a->coeffs, b->coeffs);
        asm_pointwise_fnt(r->coeffs, a->coeffs, b->coeffs, twiddles_basemul_257);
}

void polyvecl_fnt(polyvecl* a) {
	for (int i = 0; i < L; i++) {
		forward_fnt(a->vec[i].coeffs);
	}
}

void polyvecl_invfnt(polyvecl* a) {
	for (int i = 0; i < L; i++) {
		reverse_fnt(a->vec[i].coeffs);
	}
        
}


void polyvecl_pointwise_poly_forfnt(polyvecl* z, poly* cp_fnt, polyvecl* s1) {
	for (int i = 0; i < L; i++) {
		pointwise(z->vec[i].coeffs, cp_fnt->coeffs, s1->vec[i].coeffs);
	}
}


void polyveck_fnt(polyveck* a) {
	for (int i = 0; i < K; i++) {
		forward_fnt(a->vec[i].coeffs);
	}
}

void polyveck_invfnt(polyveck* a) {
	for (int i = 0; i < K; i++) {
		reverse_fnt(a->vec[i].coeffs);
	}
}

void polyveck_pointwise_poly_forfnt(polyveck* h, poly* cp_fnt, polyveck* s2) {
	for (int i = 0; i < K; i++) {
		pointwise(h->vec[i].coeffs, cp_fnt->coeffs, s2->vec[i].coeffs);
	}
}



//void schoolbook(int32_t ret[256], int32_t poly1[256], int32_t poly2[256])
//{
//	int32_t temp[512] = { 0, };
//	
//	for (int i = 0; i < 256; i++) {
//		for (int j = 0; j < 256; j++) {
//		    temp[i + j] += poly1[i] * poly2[j];
//		}
//	}
//	for (int i = 0; i < 256; i++) {
//	    temp[i] += -temp[256 + i];
//	}
//	for (int i = 0; i < 256; i++) {
//		ret[i] = temp[i];
//	}
//}

//void fnt_test()
//{
//	int32_t poly1[256] = { 2, -1, 1, -1, -2, -1, 0, 1, 2, 1, 1, -1, -1, 1, -1, -2,
//						  2, -2, 0, 1, 1, -2, 2, 1, -2, 2, 1, -2, -1, 2, 2, -1, -2,
//						  1, -2, 0, 1, 1, -1, 0, -2, -1, -1, 0, -1, 1, 0, -1, -1, 0,
//						  2, 1, 1, 1, 0, -2, -2, -1, -1, -2, 0, -2, -1, -1, 1, 2, 0,
//						  1, -1, 0, -2, -1, -1, 1, -2, 1, 2, -1, 0, -1, -1, -1, -1, 0, 
//						  -1, 1, 2, 2, 0, 1, -2, -2, 2, 2, 2, 0, -2, 0, -1, 0, 2, 0, -2,
//						  2, 0, -2, -2, -2, 2, -1, -2, 2, -1, -2, 2, 0, 1, 1, -2, 2, 0, 2,
//						 -1, 2, 1, 0, 2, 2, 0, 2, 2, -2, 1, -1, 2, 1, -1, -1, -1, 2, 2, 2, 2,
//						 -1, 2, 2, 1, -1, 2, 0, -1, -2, -1, 2, 0, 0, 0, -2, 1, -1, 2, 0, 0, -2,
//						 -2, 1, 2, 0, 0, -2, 0, -1, -1, 2, 1, -2, -2, -1, 2, 0, -2, 0, 1, 1, 0,
//						  0, -1, -1, 2, -2, 0, 1, 1, 1, 1, 2, -2, -2, 2, 1, 0, -1, -1, 1, 1,
//						  2, 2, -1, 2, 2, -1, 0, 2, -2, -1, 1, -1, 0, -2, 1, -2, 1, 2, 2, 2,
//						  0, 2, -2, 2, 1, 2, 2, 0, 0, 2, -1, -2, 0, 1, 0, -1, -2, 2, 1, -2, 1,
//						  2, -1, -1, 1, 1, 2, -2, 0, -2, -1};
//	int32_t poly2[256] = { 2, -1, 1, -1, -2, -1, 0, 1, 2, 1, 1, -1, -1, 1, -1, -2,
//						  2, -2, 0, 1, 1, -2, 2, 1, -2, 2, 1, -2, -1, 2, 2, -1, -2,
//						  1, -2, 0, 1, 1, -1, 0, -2, -1, -1, 0, -1, 1, 0, -1, -1, 0,
//						  2, 1, 1, 1, 0, -2, -2, -1, -1, -2, 0, -2, -1, -1, 1, 2, 0,
//						  1, -1, 0, -2, -1, -1, 1, -2, 1, 2, -1, 0, -1, -1, -1, -1, 0,
//						  -1, 1, 2, 2, 0, 1, -2, -2, 2, 2, 2, 0, -2, 0, -1, 0, 2, 0, -2,
//						  2, 0, -2, -2, -2, 2, -1, -2, 2, -1, -2, 2, 0, 1, 1, -2, 2, 0, 2,
//						 -1, 2, 1, 0, 2, 2, 0, 2, 2, -2, 1, -1, 2, 1, -1, -1, -1, 2, 2, 2, 2,
//						 -1, 2, 2, 1, -1, 2, 0, -1, -2, -1, 2, 0, 0, 0, -2, 1, -1, 2, 0, 0, -2,
//						 -2, 1, 2, 0, 0, -2, 0, -1, -1, 2, 1, -2, -2, -1, 2, 0, -2, 0, 1, 1, 0,
//						  0, -1, -1, 2, -2, 0, 1, 1, 1, 1, 2, -2, -2, 2, 1, 0, -1, -1, 1, 1,
//						  2, 2, -1, 2, 2, -1, 0, 2, -2, -1, 1, -1, 0, -2, 1, -2, 1, 2, 2, 2,
//						  0, 2, -2, 2, 1, 2, 2, 0, 0, 2, -1, -2, 0, 1, 0, -1, -2, 2, 1, -2, 1,
//						  2, -1, -1, 1, 1, 2, -2, 0, -2, -1 };
//
//	int32_t ret_fnt[256] = { 0, };
//	int32_t ret_sb[256] = { 0, };
//	//printf("Num of twiddles_ntt_257_streamlined: %d\n", sizeof(twiddles_ntt_257_streamlined) / sizeof(int32_t)); //128
//	//printf("Num of twiddles_intt_257_streamlined: %d\n", sizeof(twiddles_intt_257_streamlined) / sizeof(int32_t)); //120
//	//printf("Num of twiddles_basemul_257: %d\n", sizeof(twiddles_basemul_257) / sizeof(int32_t)); //64
//	//printf("poly: %d\n", sizeof(poly) / sizeof(int32_t)); //256
//	
//	
//	schoolbook(ret_sb, poly1, poly2);
//	for (int i = 0; i < 256; i++) {
//		if (ret_sb[i] < 0) {
//			ret_sb[i] += 257;
//		}
//		printf("%d ", ret_sb[i]);
//	}
//	printf("\n\n");
//
//	forward_fnt(poly1);	
//	forward_fnt(poly2);
//	for (int cnt_i = 0; cnt_i < 256; cnt_i++)
//	{
//		poly1[cnt_i] %= 257;
//		poly2[cnt_i] %= 257;
//	}
//	pointwise(ret_fnt, poly1, poly2);
//	reverse_fnt(ret_fnt);	
//
//	
//	for (int i = 0; i < 256; i++) {
//		if (ret_fnt[i] < 0) {
//			ret_fnt[i] += 257;
//		}
//		printf("%d ", ret_fnt[i]);
//	}
//	
//	int cnt = 0;
//	for (int i = 0; i < 256; i++) {
//		if (ret_sb[i] == ret_fnt[i]) {
//			cnt++;
//		}
//	}
//	if (cnt == 256) {
//		printf("\n\nsuccess\n");
//	}
//	else {
//		printf("\n\nfalse!!!!\n");
//	}
//	
//
//}

//int main()
//{
//	fnt_test();
//	return 0;
//}