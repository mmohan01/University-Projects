using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using Scattr.Resources;

using Scattr.Messages;
using GalaSoft.MvvmLight.Messaging;

namespace Scattr.Views
{
    public partial class RegisterScreen : PhoneApplicationPage
    {
        // Constructor
        public RegisterScreen()
        {
            InitializeComponent();

            // Sample code to localize the ApplicationBar
            //BuildLocalizedApplicationBar();
        }

        private void PhoneApplicationPage_Loaded(object sender, RoutedEventArgs e)
        {
            Messenger.Default.Register<NavigateToPageMessage>
                (
                    this,
                    (action) => ReceiveMessage(action)
                );

        }

        private object ReceiveMessage(NavigateToPageMessage action)
        {
            var page = string.Format("/Views/{0}View.xaml", action.PageName);
            NavigationService.Navigate(new System.Uri(page, System.UriKind.Relative));

            return null;
        }
        // Sample code for building a localized ApplicationBar
        //private void BuildLocalizedApplicationBar()
        //{
        //    // Set the page's ApplicationBar to a new instance of ApplicationBar.
        //    ApplicationBar = new ApplicationBar();

        //    // Create a new button and set the text value to the localized string from AppResources.
        //    ApplicationBarIconButton appBarButton = new ApplicationBarIconButton(new Uri("/Assets/AppBar/appbar.add.rest.png", UriKind.Relative));
        //    appBarButton.Text = AppResources.AppBarButtonText;
        //    ApplicationBar.Buttons.Add(appBarButton);

        //    // Create a new menu item with the localized string from AppResources.
        //    ApplicationBarMenuItem appBarMenuItem = new ApplicationBarMenuItem(AppResources.AppBarMenuItemText);
        //    ApplicationBar.MenuItems.Add(appBarMenuItem);
        //}
    }
}