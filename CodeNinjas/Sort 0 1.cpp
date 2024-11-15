//https://www.naukri.com/code360/problems/sort-0-1_624379
void sortZeroesAndOne(int input[], int size)
{
    //Write your code here
    int p1 = 0;
    int p2 = 0;

    for(int i = 0 ; i < size ; i++){
        if(p2 >= size) break;
        if(input[i] == 0 ){
            if(p1 == p2){
                p1++;
                p2++;
            } else {
                input[p1] = 0;
                input[p2] = 1;
                p1++;
                p2++;
            }
        }
        else{
            p2++;
        }
    }
}