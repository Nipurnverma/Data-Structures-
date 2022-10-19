

class Solution {
public:

int clumsy(int n) {
//We have total 4 operator: *, /, +, -, therefore ope will we in the range of 0-3 i.e. (modulo 4).
    int ope = 0, fact = n, temp = 0;
    
	//Operations will be performed according to BODMAS.
	// In while condition n >= 2 instead of 1 because, in case where divide is the last operation and we are doing fact / n-1(so n becomes zero and division with zero gives error therefore condition will be n >=2 . 
    while(n >= 2){
        
        if(op % 4 == 0) fact *= n-1; // 0 means *, it has higher preference than + and  -, therefore we will simply multiply.
        
        if(op % 4 == 1) fact /= n-1; // 1 means /, it has higher preference than + and  -, therefore we will simply divide.
        
		// 2 and 3 represent + and - respectively, and both have lower preference than * and /
		// therefore we will store the fact result in temp  and first perform leading * and /, if any
        if(op % 4 == 2){
			
            if(temp > 0){
                temp -= fact;
                fact = temp;
                temp = 0;
            }
            
            fact += n-1;
        }
        
		// if ope is /, we will simply store the fact in temp and perform leading * and / if any.
        if(op % 4 == 3){
            temp = fact;
            fact = n-1;
        }
        
        n--;
        op++;
    }
    
	// if temp > 0, that means last ope evaluated is not +, therefor our ans is still in temp.
    return temp > 0 ? temp - fact : fact; 
}
