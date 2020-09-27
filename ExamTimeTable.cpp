#include<iostream.h>

#include<stdlib.h>

class graph

{

	private:

	int *adj , *avail , subjects;

	public:

	graph(int no_sub)

	{

		adj = (int *)calloc(no_sub*no_sub,sizeof(int)) ;

		avail = (int *)calloc(no_sub,sizeof(int)) ;

		subjects = no_sub ;

	}

	void make()

	{

		int i , j ;

		char ch ;

		for ( i = 0 ; i < subjects ; i++ )

		{

			for ( j = i ; j < subjects ; j++ )

			{

				if ( i != j )

				{

					cout << "Enter constraint for subjects " << i+1 << " and " << j+1 << " (y/n?)= " ;

					cin >> ch ;

					if ( ch == 'y' )

					{

						adj[j+subjects*i] = 0 ;

						adj[i+subjects*j] = 0 ;

					}

					else

					{

						adj[j+subjects*i] = 1 ;

						adj[i+subjects*j] = 1 ;

					}

				}

				else

				{

					adj[i*subjects+j] = 0 ;

				}

			}

		}

	}

	int no_of_days()

	{

		int sub = subjects , flag ;

		int *color = (int *)calloc(sub,sizeof(int)) ;

		int i , j , num = 1 ;

		for ( i = 0 ; i < sub ; i++ )

		{

			color[i] = -1 ;

		}

		color[0] = 1 ;

		for ( i = 1 ; i < sub ; i++ )

		{

			flag = 0 ;

			for ( j = 0 ; j < num ; j++ )

			{

				avail[j] = 0 ;

			}

			for ( j = 0 ; j <= i-1 ;j++ )

			{

				if ( adj[j+sub*i] == 1 )

				{

					avail[color[j]-1] = 1 ;

				}

			}

			for ( j = 0 ; j < num ; j++ )

			{

				if ( avail[j] == 0 )

				{

					color[i] = j+1 ;

					flag = 1 ;

					break ;

				}

			}

			if ( flag == 0 )

			{

				num++ ;

				color[i] = num ;

			}

		}

		cout << "Color distribution = " ;

		for ( i = 0 ; i < subjects ; i++ )

		{

			cout << color[i] << " " ;

}

cout << endl ;

		return num ;

	}

};

void main()

{

	int number_of_subjects , ans ;

	cout << "Number of subjects = " ;

	cin >> number_of_subjects ;

	graph g(number_of_subjects) ;

	g.make() ;

	ans = g.no_of_days() ;

	cout << "Minimum number of days required = " << ans ;

	// color distribution printed in no_of_days function itself

}

