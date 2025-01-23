//Tehdään ensin luokka Chef, jonka sitten luokka ItalianChef perii. ItalianChef osaa siis tehdä samat ruoka-annokset kuin Chef.
//Annoksia kysyttäessä täytyy kokille antaa ainekset, joista annos valmistetaan.
//Lisäksi ItalianChef osaa tehdä salaista ruokaa (pizzaa), mutta jos sen annoksen haluaa, täytyy tietää salasana!
#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    chef nChef("Maikkuli");

    cout<<"How many ingredients are available to make salad?"<<endl;
    int saladIngredients;
    cin>>saladIngredients;
    cout<<"How many ingredients are available to make soup?"<<endl;
    int soupIngredients;
    cin>>soupIngredients;
    cout<<"Chef "<<nChef.getName()<<" made "<<nChef.makeSalad(saladIngredients)<<" salads and "<<nChef.makeSoup(soupIngredients)<<" soups"<<endl<<endl;

    italianChef iChef("Merrill");

    cout<<"How many ingredients are available to make salad?"<<endl;
    cin>>saladIngredients;
    cout<<"How many ingredients are available to make soup?"<<endl;
    cin>>soupIngredients;
    cout<<"Chef "<<iChef.getName()<<" made "<<nChef.makeSalad(saladIngredients)<<" salads and "<<nChef.makeSoup(soupIngredients)<<" soups"<<endl<<endl;

    string givenPassword;
    cout<<"Enter password to make a pizza: ";
    cin>>givenPassword;

    iChef.askSecret(givenPassword, 5, 5);


    return 0;
}


