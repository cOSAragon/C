#define TOPE 5
#define EXITO 0
#define PILALLENA 1
#define PILAVACIA 2
#define LARGOCADENA 30 
class PILA
{
	struct pags
	{
		char cadena[LARGOCADENA];
	};
	struct pags cadenas[TOPE];
	int iTope;
	int iCodError;
public:
	PILA(void);
	void Push(char Dato[]);
	char Pop(void);
	int HayError(void);
};