#include "mex.h"
#include<cstdio>
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, mxArray* prhs[]) {
	size_t m, n;
	if (mxIsStruct(prhs[0])) {
		m = mxGetM(prhs[0]);//row 
		n = mxGetN(prhs[0]);//column
		size_t numStruct = m * n;
		printf("the total number of struct is %d\n", numStruct);
		for (size_t i = 0;i < numStruct;i++) {
			printf("===the info of the %d student====\n", i + 1);
			//read scalar
			mxArray* ID = mxGetField(prhs[0], i, "id");//mxArray *
			if (ID) {
				double id = mxGetScalar(ID);
				printf("id=%f\n", id);
			}
			//read matrix
			printf("matrix=\n");
			mxArray* tmpMatrix = mxGetField(prhs[0], i, "list");
			if (tmpMatrix) {
				double* tmpmatrix = mxGetPr(tmpMatrix);//double *
				m = mxGetM(tmpMatrix);//row
				n = mxGetN(tmpMatrix);//column
				for (size_t i = 0;i < m;i++) {
					for (size_t j = 0;j < n;j++) {
						printf("%f ", *(tmpmatrix + j * m + i));
					}
					printf("\n");
				}
			}
			//read string
			mxArray* tmpString = mxGetField(prhs[0], i, "name");
			if (tmpString) {
				char* tmp = mxArrayToString(tmpString);//convert mxArray to string
					if (tmp)
						printf("name=%s\n", tmp);
			}
		}
	}
}