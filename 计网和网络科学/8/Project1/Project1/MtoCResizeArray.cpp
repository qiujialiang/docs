#include "mex.h"
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray
	* prhs[])
{
	if (nrhs != 3)
	{
		mexErrMsgTxt("������������ȷ!");
	}
	int rowNum = mxGetM(prhs[0]);
	int colNum = mxGetN(prhs[0]);
	double* pArr = (double*)mxGetPr(prhs[0]);
	//�õ�ѡ���������Ϣ
	//������������������������֧��
	double* pSelRows = (double*)mxGetPr(prhs[1]);
	double* pSelCols = (double*)mxGetPr(prhs[2]);
	int selRowsRowNum = mxGetM(prhs[1]);
	int selRowsColNum = mxGetN(prhs[1]);
	if (selRowsRowNum != 1 && selRowsColNum != 1)
	{
		mexErrMsgTxt("�в�������ȷ��");
	}
	int selRowsNum = selRowsRowNum * selRowsColNum;
	int selColsRowNum = mxGetM(prhs[2]);
	int selColsColNum = mxGetN(prhs[2]);
	if (selColsRowNum != 1 && selColsColNum != 1)
	{
		mexErrMsgTxt("�в�������ȷ��");
	}
	int selColsNum = selColsRowNum * selColsColNum;
	plhs[1] = mxCreateDoubleMatrix(2, 1, mxREAL);
	double* resizedDims = (double*)mxGetPr(plhs[1]);
	resizedDims[0] = selRowsNum;
	resizedDims[1] = selColsNum;
	plhs[0] = mxCreateDoubleMatrix(selRowsNum, selColsNum, mxREAL);
	double* pResizedArr = (double*)mxGetPr(plhs[0]);
	//������Ϊ MATLAB �����ݵð�������
#define ARR(row,col) pArr[(col)*rowNum+row]
#define RARR(row,col) pResizedArr[(col)*selRowsNum+row]
	for (int ri = 0; ri < selRowsNum; ri++)
	{
		for (int ci = 0; ci < selColsNum; ci++)
		{
			RARR(ri, ci) = ARR((int)pSelRows[ri] - 1, (int)pSelCols[ci] - 1);
		}
	}
	mexPrintf("OK!\n");
}