A = [-107.312 2.91625 0.00141533 2.78841 0.00164563 -4.46421e-06 -2.82818 2.34811e-14 2.84479e-14 -2.61148e-14 -3.15525e-15 -4.08516e-14 ; 2.91625 -85.9704 1.48713 -0.239107 1.69263 0.00024236 0.243502 1.70459 -3.88727e-14 -4.39545e-14 -1.90327e-14 1.5415e-14 ; 0.00141533 1.48713 -63.4261 0.00413478 -0.0963538 0.636315 -0.00425082 -0.0971192 -0.637101 -4.39208e-14 3.36465e-13 -5.13747e-14 ; 2.78841 -0.239107 0.00413478 -90.7243 1.81492 -1.97827e-05 0.245266 0.00981591 2.15894e-05 -1.9517 3.21345e-14 1.7354e-14 ; 0.00164563 1.69263 -0.0963538 1.81492 -68.2539 0.565303 -0.00981364 -0.123762 -0.00252086 0.128165 0.834566 -1.57477e-13 ; -4.46421e-06 0.00024236 0.636315 -1.97827e-05 0.565303 -45.4083 2.1554e-05 0.00252078 0.0218205 -0.00124856 -0.0203099 -0.115046 ; -2.82818 0.243502 -0.00425082 0.245266 -0.00981364 2.1554e-05 -90.7312 -1.81548 -2.33986e-05 1.97961 0.00048564 1.81597e-07 ; -6.87594e-16 1.70459 -0.0971192 0.00981591 -0.123762 0.00252078 -1.81548 -68.2556 -0.565358 0.13022 0.840394 1.63314e-05 ; -7.76529e-16 -1.41491e-15 -0.637101 2.15894e-05 -0.00252086 0.0218205 -2.33986e-05 -0.565358 -45.4084 0.00127172 0.020454 0.115186 ; 2.91616e-14 -7.75881e-15 -9.11891e-14 -1.9517 0.128165 -0.00124856 1.97961 0.13022 0.00127172 -73.0313 -0.784032 -1.62469e-05 ; 3.5613e-16 -7.09474e-15 -4.89465e-14 -8.40005e-15 0.834566 -0.0203099 0.00048564 0.840394 0.020454 -0.784032 -50.1037 -0.0778433 ; 3.26273e-15 -1.04504e-17 3.86526e-15 2.10548e-16 -2.01286e-13 -0.115046 1.81598e-07 1.63314e-05 0.115186 -1.62469e-05 -0.0778433 -27.3743 ; ];
b = [-122 -90 -90 -122 -90 -90 -77 -45 -45 -77 -45 -45 ]';
x = A \ b;
eig(A)
