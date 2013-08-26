#define TOPE 5
#define EXITO 0
#define COLALLENA 1
#define COLAVACIA 2
#define LARGOCADENA 30
class COLA
{
	struct pags
	{
		char cadena[LARGOCADENA];
	};
	struct pags cadenas[TOPE];
	int iMetido,iSacado;
	int iCodError;
public:
	COLA(void);
	void Push(char Dato[]);
	char* Pop(void);
	int HayError(void);

};