#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct product
{
	double weight;
	double value;
};

struct individual
{
	double fitness;
	vector< product > fenotipo;
};

void print( vector< bool * > &, int );
void print( vector< individual > &, int );
void print( const individual & );
void print( const product & );
void print( const bool [ ], int );
bool generateGene( );
void selectInd( vector< indivudual > &, int );
void crossGene( bool [ ], bool [ ], int, int );
void mutateGene( bool [ ], int, int );
void bestGene( vector< indivudual > & );
void createPopulation( vector< bool * > &, int );
double calcFitness( bool [ ], int, individual &, vector< product > & );
void setallproduct( vector< product > & );

int main()
{
	int mutationRate = ; //
	int cutPoint = ; //
	int ring = ; //
	int sizePopulation = 5;
	int numGenes = 5;
	int numGenerations = 10;	
	vector< product > allproduct( 15 );
	vector< bool * > population( sizePopulation );
	vector< individual > popDecod( sizePopulation );
		
	cout << "Programa para calcular o fitness de um gene usando aloca" << char(135) << char(198) << "o din" << char(131) << "mica de mem" << char(162) << "ria!\n\n";
	
	int k = 0;
	while( k < 10 )
	{
		k++;
		
		srand(( int ) time( 0 ));
		
		createPopulation( population, numGenes );
		print(population, numGenes);
		setallproduct( allproduct );
		
		for( int n = 0; n < sizePopulation; n++ )
			{
				 calcFitness( population[ n ], numGenes, popDecod[ n ], allproduct );
			}
		
		for ( int i = 0; i < numGenerations; i++ )
		{
			selectGene( );
			crossGene( );
			mutateGene( );
			
			for( int n = 0; n < sizePopulation; n++ )
			{
				 calcFitness( population[ n ], numGenes, popDecod[ n ], allproduct );
			}
			
			cout << "\nGeracao " << i << '\t' << "Best fitness " << popDecod[ getBestFitness( ) ].fitness << '\n';
		}
		
		for( int n = 0; n < population.size(); n++ )
		{
			delete [ ] population[ n ];
		}
	}
}

void setallproduct( vector< product > &allproduct )
{
	allproduct[ 0 ].weight = 100;
	allproduct[ 0 ].value = 1000;
	
	allproduct[ 1 ].weight = 1;
	allproduct[ 1 ].value = 10000;
	
	allproduct[ 2 ].weight = 10;
	allproduct[ 2 ].value = 100;
	
	allproduct[ 3 ].weight = 1000;
	allproduct[ 3 ].value = 10;
	
	allproduct[ 4 ].weight = 100;
	allproduct[ 4 ].value = 10;
	
	allproduct[ 5 ].weight = 10;
	allproduct[ 5 ].value = 10000;
	
	allproduct[ 6 ].weight = 100;
	allproduct[ 6 ].value = 1;
	
	allproduct[ 7 ].weight = 10;
	allproduct[ 7 ].value = 10000;
	
	allproduct[ 8 ].weight = 1000;
	allproduct[ 8 ].value = 10;
	
	allproduct[ 9 ].weight = 1;
	allproduct[ 9 ].value = 1;
	
	allproduct[ 10 ].weight = 100;
	allproduct[ 10 ].value = 100000;
	
	allproduct[ 11 ].weight = 1000;
	allproduct[ 11 ].value = 100;
	
	allproduct[ 12 ].weight = 10000;
	allproduct[ 12 ].value = 10000;
	
	allproduct[ 13 ].weight = 10;
	allproduct[ 13 ].value = 10;
	
	allproduct[ 14 ].weight = 1;
	allproduct[ 14 ].value = 1000;
}

void createPopulation( vector< bool * > &pop, int numGenes )
{
	for ( int i = 0; i < pop.size(); i++ )
	{
			pop[ i ] =  new bool[ numGenes ];
			for ( int j = 0; j < numGenes; j++ )
				pop[ i ][ j ] = generateGene( );
	}
}

bool generateGene()
{
	if( ( rand() % 100 + 1 ) <= 50 )
		return false;
		else return true;
}

void selectInd( vector< indivudual > & popDecod, int ring )
{
	vector< int > SelectedInd( popDecod.size( ) ); 
	int indexSelected;
	
	for ( int i = 0; i < ring; i++ )
		
		
	
}

void crossGene( bool ind1 [ ], bool ind2 [ ], int  numGenes, int cutPoint  )
{
	bool temp;
	
	if ( rand( ) % 100 + 1 < cutPoint )
		{
			cutPoint = rand( ) % numGenes + 1;
			
			for ( int i = cutPoint; i < numGenes; i++ )
				{
					temp = ind1[ i ];
					ind1[ i ] = ind2[ i ];
					ind2[ i ] = temp;
				}
		}
}

void mutateGene( bool chr [ ], int  numGenes, int mutationRate )
{
	for ( int i = 0; i < numGenes; i++ )
		if ( rand( ) % 100 + 1 < mutationRate )
			if ( chr[ i ] )
				chr[ i ] = false;
			else
				chr[ i ] = true;
}

int bestGene( vector< indivudual > & popDecod )
{
	int indexBest = popDecod[ 0 ];
	
	for ( int i = 1; i < popDecod.size(); i++ )
		if ( popDecod[ i ] > indexBest )
			indexBest = popDecod[ i ];
			
	return indexBest;
}

double calcFitness( bool chrom [ ], int numGenes, individual &ind, vector< product > & allproduct )
{
	ind.fitness = 0;
	
	for( int i = 0; i < numGenes; i++ )
		if( chrom[ i ] )
		{
			ind.fenotipo.push_back( allproduct[ i ] );
			
			if( allproduct[ i ].weight == 0 )
			{
				cout << "ERROR: allproduct[ i ].weight == 0";
				cin >> allproduct[ i ].weight;
			}
			
			ind.fitness += allproduct[ i ].value + 1 / allproduct[ i ].weight;
		}
}

void print(vector< bool * > &pop, int numGenes)
{
	for ( int i = 0; i < pop.size(); i++ )
		print( pop[ i ], numGenes );
}

void print( const individual &ind )
{
	cout << "Fitness = " << ind.fitness << "\n\n";
	
	for( int i = 0; i < ind.fenotipo.size( ); i++ )
		print( ind.fenotipo[ i ] );	
}

void print( const product &prod )
{
	cout << "Peso: " << prod.weight << '\t' << "Valor: " << prod.value << "\n\n"; 
}

void print( const bool chr [ ], int  numGenes )
{
	for ( int j = 0; j < numGenes; j++ )
		if( chr[ j ] )
			cout << 1 << '\t';
		else
			cout << 0 << '\t';
		cout << "\n";
}
