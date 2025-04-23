#include "nn.h"
#include <math.h>

void print(int m, int n, const float *x)
{
    for (int i = 0; i < m * n; i++)
    {

        printf("%.4f ", x[i]);
        if ((i + 1) % n == 0)
        {
            printf("\n");
        }
    }
}

void fc(int m, int n, const float *x, const float *A, const float *b, float *y)
{
    // 自分で実装
    for (int i = 0; i < m; i++)
    {
        y[i] = 0.0;
        for (int j = 0; j < n; j++)
        {
            y[i] += A[i * n + j] * x[j];
        }
        y[i] += b[i];
    }
}

void relu(int n, const float *x, float *y)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            y[i] = x[i];
        }
        else
        {
            y[i] = 0;
        }
    }
}

void softmax(int n, const float *x, float *y)
{
    float exp_sum = 0.0;
    float x_max = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x_max < x[i])
        {
            x_max = x[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        exp_sum += exp(x[i] - x_max);
    }

    for (int i = 0; i < n; i++)
    {
        y[i] = exp(x[i] - x_max) / exp_sum;
    }
}

int inference3(const float *A, const float *b, const float *x)
{
    float *y_inf = malloc(sizeof(float) * 10);
    fc(10, 784, x, A, b, y_inf);
    relu(10, y_inf, y_inf);
    softmax(10, y_inf, y_inf);

    // y_infの最大の要素を求める
    int y_max_comp = 0;
    for (int i = 1; i < 10; i++) // 10-1=9回繰り返して大きさを比較
    {
        if (y_inf[y_max_comp] < y_inf[i])
        {
            y_max_comp = i;
        }
    }
    free(y_inf);
    return y_max_comp;
}

float correct_rate_fc(int train_count, const float *A, const float *b, const float *x, unsigned char *y, int width, int height)
{
    int correct_sum = 0;
    for (int i = 0; i < train_count; i++)
    {
        int ans = inference3(A, b, x + width * height * i);
        if (ans == y[i])
        {
            correct_sum++;
        }
    }

    return ((float)correct_sum / train_count) * 100;
}

void softmaxwithloss_bwd(int n, const float *y, unsigned char t, float *dEdx)
{
    for (int i = 0; i < n; i++)
    {
        dEdx[i] = y[i] - t[i];
    }
}

// テスト
int main()
{
    float *train_x = NULL;
    unsigned char *train_y = NULL;
    int train_count = -1;
    float *test_x = NULL;
    unsigned char *test_y = NULL;
    int test_count = -1;
    int width = -1;
    int height = -1;
    load_mnist(&train_x, &train_y, &train_count,
               &test_x, &test_y, &test_count,
               &width, &height);
    // これ以降，３層 NN の係数 A_784x10 および b_784x10 と，
    // 訓練データ train_x + 784*i (i=0,...,train_count-1), train_y[0]～train_y[train_count-1],
    // テストデータ test_x + 784*i (i=0,...,test_count-1), test_y[0]～test_y[test_count-1],
    // を使用することができる．

    float correct_rate = correct_rate_fc(train_count, A_784x10, b_784x10, train_x, train_y, width, height);
    printf("%.2f%%\n", correct_rate);

    // 画像の出力
    // int i = 0;
    // save_mnist_bmp(train_x + 784 * i, "train_%05d.bmp", i);
    // return 0;

    return 0;
}
