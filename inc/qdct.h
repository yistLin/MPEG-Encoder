#ifndef QDCT
#define QDCT

#include <cmath>
#include "block.h"

// Important definition

// MAX QP for luma is 51, MAX QP for chroma is 39
const int LUMA_QP = 28;
const int CHROMA_QP = 28;
const int mat_Cf[4][4] = {
  {1,  1,  1,  1},
  {2,  1, -1, -2},
  {1, -1, -1,  1},
  {1, -2,  2, -1}
};
const int mat_Cf_T[4][4] = {
  {1,  2,  1,  1},
  {1,  1, -1, -2},
  {1, -1, -1,  2},
  {1, -2,  1, -1}
};
const int mat_MF[6][3] = {
  {13107, 5243, 8066},
  {11916, 4660, 7490},
  {10082, 4194, 6554},
  {9362,  3647, 5825},
  {8192,  3355, 5243},
  {7282,  2893, 4559}
};
const int mat_Ci[4][4] = {
  {2,  2,  2,  1},
  {2,  1, -2, -2},
  {2, -1, -2,  2},
  {2, -2,  2, -1}
};
const int mat_Ci_T[4][4] = {
  {2,  2,  2,  2},
  {2,  1, -1, -2},
  {2, -2, -2,  2},
  {1, -2,  2, -1}
};
const int mat_V[6][3] = {
  {10, 16, 13},
  {11, 18, 14},
  {13, 20, 16},
  {14, 23, 18},
  {16, 25, 20},
  {18, 29, 23}
};

// Private part
void forward_dct4x4(const int[][4], int[][4]);
void inverse_dct4x4(const int[][4], int[][4]);
void forward_quantize4x4(const int[][4], int[][4], const int);
void inverse_quantize4x4(const int[][4], int[][4], const int);
void forward_quantize2x2(const int[][2], int[][2], const int);
void inverse_quantize2x2(const int[][2], int[][2], const int);
void forward_hadamard4x4(const int[][4], int[][4]);
void inverse__hadamard4x4(const int[][4], int[][4]);
void forward_hadamard2x2(const int[][4], int[][4]);
void inverse__hadamard2x2(const int[][4], int[][4]);

// Main QDCT function used as an expandable funciton
template <typename T>
inline void qdct(T&, const int, const int);

// Public interface
void qdct_luma16x16_intra(Block16x16&);
void qdct_chroma8x8_intra(Block8x8&);
void inv_qdct_luma16x16_intra(Block16x16&);
void inv_qdct_chroma8x8_intra(Block8x8&);

#endif // QDCT
