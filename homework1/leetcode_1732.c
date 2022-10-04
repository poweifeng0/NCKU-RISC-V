#include<stdio.h>
#define gainsize(gain)  sizeof(gain)/sizeof(int)

//把gainsize直接寫入在Array後面，就不用多一個function去使用 


int largestAltitude(int* gain, int gainSize){
    int i, max, arti;
	arti = 0;
	max=arti;
    for(i=0;i<gainSize;i++){
        arti=arti+gain[i];
        if(arti>max){max = arti;}    
    }
    return max;
    
}

int main(){
    
    int gain[]={-1,5,4};
    int gainSize = 3;
    printf("gainsize=%d\n",gainSize);
    int max = largestAltitude(gain,gainSize);
    printf("max1=%d\n",max);

    int gain2[]={-5,1,5,0,-7};
    gainSize = 5;
    printf("gainsize=%d\n",gainSize);
    max = largestAltitude(gain2,gainSize);
    printf("max2=%d\n",max);

    int gain3[]={-5,1,3};
    gainSize = 3;
    printf("gainsize=%d\n",gainSize);
    max = largestAltitude(gain3,gainSize);
    printf("max3=%d\n",max);

    return 0 ;
    

}
