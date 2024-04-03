#include <stdio.h>

#define TILE_WIDTH 32
#define RADIUS 1

__global__ void convolution_1d(float *input, float *output, int width) {
    __shared__ float tile[TILE_WIDTH + 2 * RADIUS];

    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int tx = threadIdx.x;

    tile[tx + RADIUS] = (i < width) ? input[i] : 0.0f;
    if (tx < RADIUS) {
        tile[tx] = (i - RADIUS >= 0) ? input[i - RADIUS] : 0.0f;
        tile[tx + TILE_WIDTH + RADIUS] = (i + blockDim.x < width) ? input[i + blockDim.x] : 0.0f;
    }

    __syncthreads();

    if (i < width) {
        float result = 0.0f;
        for (int j = 0; j < 2 * RADIUS + 1; j++) {
            result += tile[tx + j] * (i+1);
        }
        output[i] = result;
    }
}

int main() {
    int width = 7;
    float *input, *output;
    float *d_input, *d_output;

    input = (float*)malloc(width * sizeof(float));
    output = (float*)malloc(width * sizeof(float));

    cudaMalloc(&d_input, width * sizeof(float));
    cudaMalloc(&d_output, width * sizeof(float));

    for (int i = 0; i < width; i++) {
        input[i] = i+1;
    }

    cudaMemcpy(d_input, input, width * sizeof(float), cudaMemcpyHostToDevice);

    convolution_1d<<<(width + TILE_WIDTH - 1) / TILE_WIDTH, TILE_WIDTH>>>(d_input, d_output, width);

    cudaMemcpy(output, d_output, width * sizeof(float), cudaMemcpyDeviceToHost);

    for (int i = 0; i < width; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(input);
    free(output);
    cudaFree(d_input);
    cudaFree(d_output);

    return 0;
}