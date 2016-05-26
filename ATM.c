#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
struct User
{
	int id;
	int pin;
	int card_number;
	float balance;
};

struct User *User_create()
{
	struct User *object = malloc(sizeof(User));
	assert(object != NULL);
	return object;
	int fd;
	fd=open("buff.txt", O_RDONLY | O_CREAT);
	if(fd==-1){
				perror("Open");
				return 2;
	}
	fscanf(fp, "%d %d %d %e", object->id, object->card_number, object->pin, object->balance);
}

void User_delete(struct  User *object)
{
	assert(object != NULL);
	free(object);
}

void Withdraw(struct User*object)
{
	int i = 0;
	int value;
	printf("\nHow much would you like to withdraw? . . . ");
	scanf("%d", &value);
	if (object->balance < value)
		printf("\nInsufficient amount! Your available balance is %f", object->balance);
	i++;
	object->balance -= value;
}
void PrintBalance(struct User*object)
{
	printf("\nYour available balance is %e", object->balance);
}

int main(int argc, char** argv)
{
	struct User *user1 = User_create();
	printf("\nPlease choose a language");
	printf("\nPor favor seleccione el lenguaje");
	printf("\n1.English");
	printf("\n2.Espanol");
	int choice;
	int code;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\nPlease enter PIN code:\n");
		scanf("%d", &code);
		if (code == user1->pin)
			printf("\nSuccess!");
		printf("\nPlease choose an operation:");
		printf("\n1.Withdraw");
		printf("\n2.Check Balance");
		int operation;
		scanf("%d", &operation);
		switch (operation) {
		case 1:
			Withdraw(user1);
			break;
		case 2:
			PrintBalance(user1);
			break;
		default:
			perror("\nWrong operation!");
			break;
		}
		break;
	case 2:
		printf("\nPor favor, inserte el pasador(PIN):\n");
		scanf("%d", &code);
		if (code == user1->pin)
			printf("\nSuccess!");
		printf("\nPor favor, seleccione una operación:");
		printf("\n1.Withdraw");
		printf("\n2.Check Balance");
		
		scanf("%d", &operation);
		switch (operation) {
		case 1:
			Withdraw(user1);
			break;
		case 2:
			PrintBalance(user1);
			break;
		default:

			perror("\Operación incorrecta!");
			break;
		}
	}
		printf("\nThank you for using our ATM!");
		printf("\nGracias por utilizar este ATM!");
		exit(1);
		return 0;

}



