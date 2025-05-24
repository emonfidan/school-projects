// Here you can define the function prototype in different ways. For example,
// instead of using pass-by-reference, you can simulate pass-by-reference.
// In that case, you need to modify your statements as well.
int *selectNegativesModifie(int *&arr, int &size, int &outputSize){
// calculate the number of negative entries in the output array
outputSize = 0;
for (int i = 0; i < size; i++)
if (arr[i] < 0)
outputSize++;
// if this number is 0, it means that there are no negative entries in the
// input array, and thus, the output array is NULL and the input array
// and its size remain unchanged
if (outputSize == 0)
return nullptr;
// if there are negative entries in the input array, allocate the output
// array and another temporary array that will contain the non-negative
// entries. Here we have to allocate a temporary array since we will still
// use the input array to read its contents. Once we are done with it, we
// will deallocate the input array and assign the temporary array to it
int *output = new int[outputSize];
int tmpSize = size - outputSize;
int *tmpArr, cnt = 0, tmpCnt = 0;
// tmpSize = 0 means that all entries in the input array are negatives
// so that the input array should become empty after the function call
if (tmpSize == 0)
tmpArr = nullptr;
else
tmpArr = new int[tmpSize];
for (int i = 0; i < size; i++)
if (arr[i] < 0)
output[cnt++] = arr[i];
else
tmpArr[tmpCnt++] = arr[i];
// as aforementioned, we will deallocate the input array and assign the
// temporary array, which contains non-negative values, to it. We are also
// changing the size of the input array
delete []arr;
arr = tmpArr;
size = tmpSize;
return output;
}
int main(){
    return 0;
}
