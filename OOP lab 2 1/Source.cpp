#include "Libraries.h"
#include "Tour.h"
#include "Tourist.h"
void main(){
	Tour tour_ukraine("Ukraine", 10, 4, "HUkraine", "a", "bus", 200, 11);//�������� ���'���
	Tour tour_france("France", 11, 5, "HFrance", "b", "plane", 1000, 15);//�������� ���'���
	cout << "Hello! The rules of the program. If you want to say yes, press 1, if no - press 0" << endl;
	Tourist tourist("Ivan", "Ivanov", 2010, 25, 65442, 63592565, 63474, 10000);//�������� ���'���
	cout << "What tour do you want?" << endl;
	Tour *tour_mass = new Tour[2];//�� �� ������ ��� Tour(){},�������� ���'���,����� ��'����
	tour_mass[0] = tour_ukraine;//������ � ��'������ � �����
	tour_mass[1] = tour_france;//������ � ��'������ � �����
	int count_orders = 0;
	string country_tour;
	cin >> country_tour;
	count_orders++;
	tourist.ChooseTour(tour_mass, country_tour, 2);
	bool yes_no = 0;
	cout << "Do you need other or one more tour?" << endl;
	cin >> yes_no;
	cout << "Enter country:" << endl;
	cin >> country_tour;
	if (yes_no == 1){
		count_orders++;
		tourist.ChooseTour(tour_mass, country_tour, 2);
	}
	cout << "Do you want pay for order(s)" << endl;
	cin >> yes_no;

	if (yes_no == 1){
		cout << "Last price your orders is " << tourist.GetOrdersPrice(count_orders) << ". Do you want pay by card: " << tourist.getCardNumber() << " ?" << endl;
		//cout << "Last price your orders is " << tourist.GetOrdersPrice() << ". Do you want pay by card: " << tourist.getNumberCard() << " ?" << endl;
	}
	cin >> yes_no;
	if (yes_no == 1){
		tourist.PayForTour(tourist.GetOrdersPrice(count_orders));
	}
	else{
		cout << "Please, enter new cardnumber" << endl;
		int cardnumber;
		cin >> cardnumber;
		tourist.setCardNumber(cardnumber);
		if (tourist.getCardNumber() % 2 == 0){
			tourist.PayForTour();
		}
		else
		tourist.PayForTour(tourist.GetOrdersPrice(count_orders));
	}
	cin.get();
	cin.get();
}