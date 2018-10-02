#include "calc.h"

int main() {

	int selectMenu = 0;
	int data1 = 0, data2 = 0;

	while ((selectMenu = menu_choice()) != 5) {
		insert_target(&data1, &data2);
		show_result(start_calc(data1, data2, selectMenu));
	}

	return 0;
}