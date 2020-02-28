bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        for (int i=0; i<A.size(); i++) {
            sum += A[i];
        }
        if (sum % 3 != 0 ) return false;
        sum /= 3;
        int sum1=0, sum2=0,i =0, j=A.size()-1;
        while (i<j) {
            if (sum1 != sum) sum1 += A[i++];
            if (sum2 != sum) sum2 += A[j--];
            if (sum1 == sum && sum2 == sum) {
                return true;
            }
        }
        return false;
}

//ran out of time
bool canThreePartsEqualSum1(vector<int>& A) {
    long int add1=0, tadd2=0, add3=0;
    for (int i=0; i<A.size(); i++) {
        tadd2 += A[i];
    }
    for (int i=0; i<A.size()-2; i++) {
        int add2 = tadd2, add3 = 0;
        add1 += A[i];
        add2 -= A[i];
        tadd2 = add2;
        for(int j=A.size()-1; j>i+1; j--) {
            add3 += A[j];
            add2 -= A[j];
            if (add1 == add2 && add3 == add2) {
                return true;
            }
        }
    }
    return false;
}

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(),0);
        if (sum % 3 != 0 ) return false;
        int avg = sum / 3;
        int want = avg, sum1=0;
        for (int i=0; i<A.size(); i++) {
            sum1 += A[i];
            if (sum1 == want) want += avg;
        }
        return (want == avg*4);
    }
};