#include "mex.h"
#include <vector>
#include <limits>
#include <cmath>

const int INF = 32767;
const int MAXN = 10;

// Dijkstra�㷨��ʵ��
void Dijkstra(int v, const double A[MAXN][MAXN], double dis[MAXN], int path[MAXN]) {
    bool S[MAXN] = { false };
    int n = MAXN;
    for (int i = 0; i < n; ++i) {
        dis[i] = A[v][i];
        if (dis[i] == INF) dis[i] = NAN; // ������ɴ����ΪNaN
        path[i] = -1;
    }

    dis[v] = 0;
    S[v] = true;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        double minDist = INF;

        // Ѱ�Ҳ���S���Ҿ�����С�Ķ���u
        for (int j = 0; j < n; ++j) {
            if (!S[j] && (u == -1 || dis[j] < minDist)) {
                u = j;
                minDist = dis[j];
            }
        }

        if (u == -1) break; // ʣ�ඥ�㶼���ɴ�

        S[u] = true;

        // ���¶���u���ڵĶ���ľ���
        for (int j = 0; j < n; ++j) {
            if (!S[j] && A[u][j] != INF && dis[u] + A[u][j] < dis[j]) {
                dis[j] = dis[u] + A[u][j];
                path[j] = u;
            }
        }
    }
}

// MEX�ļ�����ڵ�
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {

    // ��ȡ�������
    int src = static_cast<int>(mxGetScalar(prhs[0]));
    double* graphPtr = mxGetPr(prhs[1]);

    // �����������
    plhs[0] = mxCreateDoubleMatrix(MAXN, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(MAXN, 1, mxREAL);

    // ������ͼת��ΪC++����
    double A[MAXN][MAXN];
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            A[i][j] = graphPtr[i + j * MAXN];
        }
    }

    // ����Dijkstra�㷨
    double* disPtr = mxGetPr(plhs[0]);
    int* pathPtr = reinterpret_cast<int*>(mxGetPr(plhs[1])); // ʹ��reinterpret_cast��������ת��
    double dis[MAXN];
    int path[MAXN];
    Dijkstra(src, A, dis, path);

    // ��������ƻ�Matlab����
    for (int i = 0; i < MAXN; ++i) {
        disPtr[i] = dis[i];
        if (path[i] == -1) {
            pathPtr[i] = 0; // ���û��·����������Ϊ0
        }
        else {
            pathPtr[i] = path[i] + 1; // MATLAB������1��ʼ
        }
    }
}