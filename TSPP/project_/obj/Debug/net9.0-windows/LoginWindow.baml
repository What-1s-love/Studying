   M S B A M L   `   `   `  ����I  EПогодка, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null/clr-namespace:ПогодкаПогодка  5   	        Погодка.LoginWindow   5   	   W SPresentationCore, Version=9.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=9.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=9.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=9.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=9.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   .localclr-namespace:Погодка     5   	     � Title$  Авторизація��5   	   $	��300��6   $	��400��6*    � WindowStartupLocation$ CenterScreen=�5	   	    � 	Resources 5         LoginButtonStyle �� 
TargetType �� Property �� Value �� 
TargetType �� CornerRadius �� Triggers	 P� Property
 P� Value��%f  &	        �� 5   
   " ��6)   .�5      ��  � ��$
 10,5q�6(   �� 5       � ��$ 0,20,0,0q�6'   �� 5       � �� �#4CAF506+   �� 5       � ��
 �����6+   �� 5       � �� �#388E3C6,   �� 5       � ��$ 1q�60   �� 5       � ��$ 14(�6)   �� 5       � ��$ Stretch=�64   �� 5       � �� 5      �� 5      " ��6&   .R�5      �� #��z��6!   #��z��5   !   #��z��5   !   $ 8��5   !   ._�5      �� #��z��6/   #��z��5   /   #��z��5   /   5      5       5"       5$      P� 5%      	 �@J�IsMouseOver$

 True��61   . �5&      ��  � �� �#4CAF5063   �� 5'       � ��
 �����63   5(      P� 5)      	 � ��$

 True��6/   . �5*      ��  � �� �#4CAF5063   �� 5+       � ��
 �����63   5,      5.      5/      .��51      � .+�52   
   ��  �� Orientation$ Vertical=�6   $��Center=�53      $��Center=�54      $	��300��55      .+�56      �� $��Авторизація��6   $��20(�57      $
��Bold"�58      $��Center=�59      $��0,0,0,20q�5:      �� 5<      $��
Логін��6   $��0,0,0,5q�6%   �� 5=      -   5         ��Name$ LoginTextBox��5=      $��5q�6,   �� 5?      $��Пароль��6   $��0,10,0,5q�6&   G� 5@      -   5         G�Name$ PasswordPasswordBox��5@      $��5q�67   �� 5B      -   5         ��Name$ LoginButton��5C      $��Увійти��5B      #��[  5D      5E      5F      5G      5H      