/*
    COPYRIGHT
*/

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORD_LENGTH 64

__global__ void countWordKernel(const char* sentence, const char* word, int* count, int sentenceLength, int wordLength) {
    int tid = threadIdx.x;

    while (tid < sentenceLength) {
        int i = 0;
        while (i < wordLength && sentence[tid + i] == word[i]) {
            i++;
        }

        if (i == wordLength) {
            atomicAdd(count, 1);
            tid += wordLength;
        } else {
            tid++;
        }
    }
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH] = "This is a sample sentence. This sentence contains the word sample multiple times.";
    char word[MAX_WORD_LENGTH] = "sample";

    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);

    char* d_sentence;
    char* d_word;
    int* d_count;

    cudaMalloc((void**)&d_sentence, sentenceLength * sizeof(char));
    cudaMalloc((void**)&d_word, wordLength * sizeof(char));
    cudaMalloc((void**)&d_count, sizeof(int));

    cudaMemcpy(d_sentence, sentence, sentenceLength * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, wordLength * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemset(d_count, 0, sizeof(int));

    int blockSize = 1;
    int gridSize = 1;

    countWordKernel<<<gridSize, blockSize>>>(d_sentence, d_word, d_count, sentenceLength, wordLength);

    int result;
    cudaMemcpy(&result, d_count, sizeof(int), cudaMemcpyDeviceToHost);

    printf("The word '%s' appears %d times in the sentence.\n", word, result);

    cudaFree(d_sentence);
    cudaFree(d_word);
    cudaFree(d_count);

    return 0;
}