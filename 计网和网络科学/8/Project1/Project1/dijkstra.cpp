#include "mex.h"
#include <vector>
#include <limits>
#include <cmath>

const int INF = 32767;
const int MAXN = 10;

// Dijkstra算法的实现
void Dijkstra(int v, const double A[MAXN][MAXN], double dis[MAXN], int path[MAXN]) {
    bool S[MAXN] = { false };
    int n = MAXN;
    for (int i = 0; i < n; ++i) {
        dis[i] = A[v][i];
        if (dis[i] == INF) dis[i] = NAN; // 如果不可达，设置为NaN
        path[i] = -1;
    }

    dis[v] = 0;
    S[v] = true;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        double minDist = INF;

        // 寻找不在S中且距离最小的顶点u
        for (int j = 0; j < n; ++j) {
            if (!S[j] && (u == -1 || dis[j] < minDist)) {
                u = j;
                minDist = dis[j];
            }
        }

        if (u == -1) break; // 剩余顶点都不可达

        S[u] = true;

        // 更新顶点u相邻的顶点的距离
        for (int j = 0; j < n; ++j) {
            if (!S[j] && A[u][j] != INF && dis[u] + A[u][j] < dis[j]) {
                dis[j] = dis[u] + A[u][j];
                path[j] = u;
            }
        }
    }
}

// MEX文件的入口点
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {

    // 获取输入参数
    int src = static_cast<int>(mxGetScalar(prhs[0]));
    double* graphPtr = mxGetPr(prhs[1]);

    // 创建输出参数
    plhs[0] = mxCreateDoubleMatrix(MAXN, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(MAXN, 1, mxREAL);

    // 将输入图转换为C++数组
    double A[MAXN][MAXN];
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            A[i][j] = graphPtr[i + j * MAXN];
        }
    }

    // 调用Dijkstra算法
    double* disPtr = mxGetPr(plhs[0]);
    int* pathPtr = reinterpret_cast<int*>(mxGetPr(plhs[1])); // 使用reinterpret_cast进行类型转换
    double dis[MAXN];
    int path[MAXN];
    Dijkstra(src, A, dis, path);

    // 将结果复制回Matlab矩阵
    for (int i = 0; i < MAXN; ++i) {
        disPtr[i] = dis[i];
        if (path[i] == -1) {
            pathPtr[i] = 0; // 如果没有路径，则设置为0
        }
        else {
            pathPtr[i] = path[i] + 1; // MATLAB索引从1开始
        }
    }
}