#ifdef __cplusplus
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

__declspec( dllimport ) int gcd( int a, int b);
/* __declspec( dllimport ) void MyCFunc(); */
/* __declspec( dllimport ) void AnotherCFunc(); */

#ifdef __cplusplus
}
#endif
