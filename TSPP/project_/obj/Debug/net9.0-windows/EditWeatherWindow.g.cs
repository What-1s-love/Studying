﻿#pragma checksum "..\..\..\EditWeatherWindow.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "7B35A8734E98745EFFDCCB1F6658C87A5C1FD78E"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Controls.Ribbon;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;
using Погодка;


namespace Погодка {
    
    
    /// <summary>
    /// EditWeatherWindow
    /// </summary>
    public partial class EditWeatherWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 100 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DatePicker AddDateDatePicker;
        
        #line default
        #line hidden
        
        
        #line 103 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox AddTemperatureTextBox;
        
        #line default
        #line hidden
        
        
        #line 106 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox AddPrecipitationTextBox;
        
        #line default
        #line hidden
        
        
        #line 109 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox AddWindTextBox;
        
        #line default
        #line hidden
        
        
        #line 112 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button AddRecordButton;
        
        #line default
        #line hidden
        
        
        #line 123 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.DatePicker DeleteDateDatePicker;
        
        #line default
        #line hidden
        
        
        #line 126 "..\..\..\EditWeatherWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button DeleteRecordButton;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "9.0.2.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/Погодка;component/editweatherwindow.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\EditWeatherWindow.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "9.0.2.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.AddDateDatePicker = ((System.Windows.Controls.DatePicker)(target));
            return;
            case 2:
            this.AddTemperatureTextBox = ((System.Windows.Controls.TextBox)(target));
            return;
            case 3:
            this.AddPrecipitationTextBox = ((System.Windows.Controls.TextBox)(target));
            return;
            case 4:
            this.AddWindTextBox = ((System.Windows.Controls.TextBox)(target));
            return;
            case 5:
            this.AddRecordButton = ((System.Windows.Controls.Button)(target));
            return;
            case 6:
            this.DeleteDateDatePicker = ((System.Windows.Controls.DatePicker)(target));
            return;
            case 7:
            this.DeleteRecordButton = ((System.Windows.Controls.Button)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}

