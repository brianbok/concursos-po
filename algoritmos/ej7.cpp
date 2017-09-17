#include <iostream>
#include <vector>

using namespace std;

int count_y_ord(int a[], int start, int end, int merge[]){
	int cant = end - start;
	
	if (cant <= 1){
		return 0;
	}
	
	int m = (start + end) / 2;
	
	int res = 0;
	
	res += count_y_ord(a, start, m, merge); 
	res += count_y_ord(a, m, end, merge);
	
	int pos_merged = start; 
	int mergeados = 0;
	int p_izq = start, p_der = m;
	
	int merged_der = 0;
	
	while (mergeados < cant){
		if (p_izq < m and p_der < end){
			
			if (a[p_izq] <= a[p_der]){
				merge[pos_merged++] = a[p_izq++];
				res += merged_der;
			} else {
				merge[pos_merged++] = a[p_der++];
				merged_der++;
			}
			
		} else if (p_izq < m) {
			
			merge[pos_merged++] = a[p_izq++];
			res += merged_der;
		
		} else { // p_der < end
				
			merge[pos_merged++] = a[p_der++];
			merged_der++;
			
		}
		
		mergeados++;
		
	}
	
	std::copy(merge+start, merge+end, a+start);
	
	return res;
	
}

int main(){
	int n;
	cin >> n;
	
	int a[n];
	int merge[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	std::cout << count_y_ord(a, 0, n, merge)<<endl;

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	cout << endl;

	
}
