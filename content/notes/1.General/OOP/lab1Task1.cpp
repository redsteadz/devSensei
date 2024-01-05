#include <iostream>
#include <cmath>
using namespace std;

class Cart{
  public:
  int quantity;
  float priceOfBag = 5.5;
  void setQuantity(int q){
    quantity = q;
  }
};

class Bill{
  private:
    int lBoxCap = 20;
    float lBoxCost = 1.8;
    int mBoxCap = 10;
    float mBoxCost = 1.0;
    int sBoxCap = 5;
    float sBoxCost = 0.6;
    float totalCost = 0;
  public:
    void calculateBill(Cart c){
      int quantity = c.quantity;
      if (quantity >= lBoxCap){
       std::cout << quantity/lBoxCap << "Large Boxes: " << (int)(quantity/lBoxCap)*lBoxCost << std::endl;
       totalCost += (int)(quantity/lBoxCap)*lBoxCost;
       quantity = quantity % lBoxCap;
      }
      if (quantity >= mBoxCap){
       std::cout << quantity/mBoxCap << "Medium Boxes: " << (int)(quantity/mBoxCap)*mBoxCost << std::endl;
       totalCost += (int)(quantity/mBoxCap)*mBoxCost;
       quantity = quantity % mBoxCap;
       // cout << quantity << endl;
      }
      if (quantity >= 0){
        int sBox = ceil((float) quantity/sBoxCap);
       std::cout << sBox << "Small Boxes: " << sBox*sBoxCost << std::endl;
       totalCost += sBox*sBoxCost;
      }

      cout << "Total Cost: " << totalCost + c.quantity*c.priceOfBag << endl;

    }
};

int main (int argc, char *argv[]) {
  Bill b;
  Cart c;
    c.quantity = 52;
  std::cout << "The Cost of Order: " << c.quantity * c.priceOfBag << std::endl;
  b.calculateBill(c);

  return 0;
}
