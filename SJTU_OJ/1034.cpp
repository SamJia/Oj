#include <cstdio>
main(){
	int total_length, need_length, list[420000] = {0}, start_pos = 0, min_rp = 2000000000, tmp_max, tmp_end, i;
	scanf("%d%d", &total_length, &need_length);
	for(int i = 0; i < total_length; ++i)
		scanf("%d", &list[i]);
	for(int i = 0; i < need_length; ++i)
		list[total_length + i] = list[i];
	while(start_pos < total_length){
		tmp_max = 0, tmp_end = start_pos + need_length;
		for(i = start_pos; i < tmp_end; ++i)
			if(list[i] >= tmp_max){
				tmp_max = list[i];
				start_pos = i + 1;
				if(tmp_max >= min_rp)
					break;
			}
		if(i == tmp_end)
			min_rp = tmp_max;
	}
	printf("%d\n", min_rp);
}