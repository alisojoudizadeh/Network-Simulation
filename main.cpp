#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

void show ( double[][5] , int ) ;
void show_det ( int[][3] , int ) ;
void show_st( double[][9] , int , int  );

int main()
{
    cout << "Step 1 : Arrival Time Table Information : " << endl ;
    /* Step 1 */
    int n = 0 ;
    cout << "Enter your n value : " ;
    cin >> n ;
    double arrival [0][5] = {0};
    for ( int i = 0 ; i <= n - 1 ; i++ )
    {
        cout << "Please set your " << i + 1 << " arrival time : " ;
        cin >> arrival[i][0]  ;

    }

    for ( int i = 0 ; i <= n - 1 ; i++ )
    {
        double apro ;
        cout << "Please enter Probability of " << i + 1 << "'s Arrivals : " ;
        cin >> apro;
        arrival[i][1] = apro ;

    }

    arrival[0][2] = arrival[0][1] ;

    for ( int q = 1 ; q <= n -1  ; q++ )
    {

        arrival[q][2] = arrival[q-1][2] + arrival[q][1] ;

    }

    double min = 1.1 ;
    for ( int i = 0 ; i <= n - 1 ; i++ )
    {
        if ( arrival[i][1] < min )
        {
            min = arrival[i][1];
        }
    }

    int tedad_ashar = 0 ;
    for ( int i = 1 ; i <= 6 ; i++ )
    {
        if ( min * pow(10,i) - int(min*pow(10,i)) > 0 )
        {
            tedad_ashar++;
        }
        else
        {
            break;
        }
    }
    ++tedad_ashar;


    arrival[0][3] = 1 ;
    double w ;
    w = arrival[0][2] ;
    arrival[0][4] = int ( w * pow(10,tedad_ashar) )  ;
    for ( int i = 1 ; i <= n - 1 ; i++  )
    {
            w = arrival[i][2] ;
            arrival[i][3] = int  ( arrival[i-1][4] )  + 1 ;
            arrival[i][4] = int  ( w * pow(10,tedad_ashar) ) ;
    }
    if (arrival[n-1][4]  == pow(10,tedad_ashar) - 1 )
        arrival[n-1][4]++;

    /*Step1 */


    /*Step 2 */
    int m = 0 ;
    cout << "Step 2 : Service Time Table Information : " << endl ;
    cout << "Enter your m value : " ;
    cin >> m ;
    double service[m][5] = {0};
    for ( int i = 0 ; i <= m - 1 ; i++ )
    {
        cout << "Please set your " << i + 1 << " service time : " ;
        cin >> service[i][0]  ;

    }

    for ( int i = 0 ; i <= m - 1 ; i++ )
    {
        double spro ;
        cout << "Please enter Probability of " << i + 1 << "'s Service Time : " ;
        cin >> spro;
        service[i][1] = spro ;

    }

    service[0][2] = service[0][1] ;

    for ( int q = 1 ; q <= m -1  ; q++ )
    {

        service[q][2] = service[q-1][2] + service[q][1] ;

    }

    double min2 = 1.1 ;
    for ( int i = 0 ; i <= m - 1 ; i++ )
    {
        if ( service[i][1] < min2 )
        {
            min2 = service[i][1];
        }
    }

    int tedad_ashar2 = 0 ;
    for ( int i = 1 ; i <= 6 ; i++ )
    {
        if ( min2 * pow(10,i) - int( min2 *pow(10,i)) > 0 )
        {
            tedad_ashar2++;
        }
        else
        {
            break;
        }
    }
    ++tedad_ashar2;


    service[0][3] = 1 ;
    double w2 ;
    w2 = service[0][2] ;
    service[0][4] = int ( w2 * pow(10,tedad_ashar2) )  ;
    for ( int i = 1 ; i <= m - 1 ; i++  )
    {
            w2 = service[i][2] ;
            service[i][3] = int  ( service[i-1][4] )  + 1 ;
            service[i][4] = int  ( w2 * pow(10,tedad_ashar2) ) ;
    }
    if (service[m-1][4]  == pow(10,tedad_ashar2) - 1 )
        service[m-1][4]++;



    /*step 3 */
    cout << "Step 3 : time between arrivals determination : " << endl ;
    int k = 0 ;
    cout << "Enter your k value : " ;
    cin >> k ;
    int adet[k][3] = {0};
    for ( int i = 0 ; i <= k - 1 ; i++ )
    {
        adet[i][0] = i + 1  ;

    }

    int rand_dig ;
    srand( time(0) );
    for ( int i = 1 ; i <= k - 1 ; i++ )
    {
        rand_dig = rand() % int ( pow(10,tedad_ashar) ) ;
        adet[i][1] = rand_dig ;
    }

    for ( int i = 1 ; i <= k - 1 ; i++ )
    {

        for ( int j = 0 ; j <= n - 1 ; j++ )
        {
            if ( ( adet[i][1] >= arrival[j][3] ) && ( adet[i][1] <= arrival[j][4] ) )
            {
                adet[i][2] = arrival[j][0] ;
            }
        }


    }
    /*Step 3 */


    /*Step 4 */
    cout << "Step 4 : Service time determination : " << endl ;
    int b = 0 ;
    cout << "Enter your b value : " ;
    cin >> b ;
    int sdet[b][3] = {0};
    for ( int i = 0 ; i <= b - 1 ; i++ )
    {
        sdet[i][0] = i + 1  ;

    }

    int rand_dig2 ;
    srand( time(0) );
    for ( int i = 0 ; i <= b - 1 ; i++ )
    {
        rand_dig2 = rand() % int ( pow(10,tedad_ashar2) ) ;
        sdet[i][1] = rand_dig2 ;
    }

    for ( int i = 0 ; i <= b - 1 ; i++ )
    {

        for ( int j = 0 ; j <= m - 1 ; j++ )
        {
            if ( ( sdet[i][1] >= service[j][3] ) && ( sdet[i][1] <= service[j][4] ) )
            {
                sdet[i][2] = service[j][0] ;
            }
        }

    }
    /*Step 4 */

    /*Step 5 */
    cout << "Step 5 : Simulation table for queuing problem : " << endl ;
    double simt[k][9] = {0};

    for ( int i = 0 ; i <= k - 1 ; i++ )
    {
        simt[i][0] = i + 1 ;
    }

    for ( int i = 0 ; i <= k - 1 ; i++ )
    {
        for ( int j = 0 ; j <= k - 1 ; j++ )
        simt[i][1] = adet[i][j] ;
    }

    simt[0][2] = 0 ;
    for ( int i = 0 ; i <= k - 1 ; i++ )
    {
        simt[i][2] = simt[i][1] + simt[i-1][2] ;
    }

    for ( int i = 0 ; i <= k - 1 ; i++ )
    {
        simt[i][3] = sdet[i][2] ;
    }

    int timeline = 4 ;
    simt[0][4] = 0 ;
    for ( int i = 1 ; i <= k - 1 ; i++ )
    {

        if ( simt[i][2] < timeline )
        {
            while ( (simt[i-1][2] + simt[i-1][3]) > simt[i][2] )
            {
                timeline++;
            }
            simt[i][4] = timeline ;
        }
        else if ( simt[i][2] > timeline )
        {
            simt[i][4] = simt[i][2] ;
            timeline += simt[i][3] ;
        }
        else
        {

        }
    }
    /* Step 5 */





    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    int request = 100 ;
    while ( request != 0 )
    {
        cout << "Enter Your Request : "
             << "\n 1-Show distribution table of time between arrivals  "
             << "\n 2-Show distribution table of service time "
             << "\n 3-Show TBA Determination  "
             << "\n 4-Show ST Determination "
             << "\n 5-Show Simulation Table "
             << "\n 0-Exit" << endl ;
        cin >> request ;
        if ( request == 1 )
        {
            show ( arrival , n );
        }
        else if ( request == 2 )
        {
            show ( service , m ) ;
        }
        else if ( request == 3 )
        {
            show_det ( adet , k ) ;
        }
        else if ( request == 4 )
        {
            show_det( sdet , b ) ;
        }
        else if ( request == 5 )
        {
            show_st( simt , 9 , k );
        }
    }

    return 0 ;
}

void show( double execute[][5] , int n )
{
    for ( int i = 0 ; i <= n - 1 ; i++ )
        {
            for ( int j = 0 ; j <= 4 ; j++ )
            {
                if ( j != 4 && j != 3 && j != 0 )
                {
                    cout << setiosflags( ios::showpoint | ios::fixed )  << setprecision(3) << execute[i][j] << "   ";
                }
                else if ( j == 0 )
                {
                    cout << int( execute[i][j] ) << "   " ;
                }
                else if ( j == 3 )
                {
                    cout << int( execute[i][j] ) ;
                }
                else if ( j == 4 )
                {
                    cout <<"-" << int( execute[i][j] ) ;
                }
            }
            cout << endl ;
        }
}

void show_det ( int execute[][3] , int n )
{
    for ( int i = 0 ; i <= n - 1 ; i++ )
        {
            for ( int j = 0 ; j <= 2 ; j++ )
            {
                cout <<  execute[i][j]  << "   " ;
            }
            cout << endl ;
        }
}

void show_st( double execute [][9] , int n , int k )
{
    for ( int i = 0 ; i <= k - 1 ; i++ )
        {
            for ( int j = 0 ; j <= 8 ; j++ )
            {
                cout <<  execute[i][j]  << "   " ;
            }
            cout << endl ;
        }
}
