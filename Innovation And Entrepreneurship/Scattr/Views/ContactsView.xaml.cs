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
    public partial class ContactsView : PhoneApplicationPage
    {
        public ContactsView()
        {
            InitializeComponent();
        }

        
        private void PhoneApplicationPage_Loaded(object sender, System.Windows.RoutedEventArgs e)
        {
        	Messenger.Default.Register<NavigateToPageMessage>
                (
                    this, (action) => ReceiveMessage(action)
                );
        }
		
		private object ReceiveMessage(NavigateToPageMessage action)
        {
            var page = string.Format("/Views/{0}View.xaml", action.PageName);

            NavigationService.Navigate(new System.Uri(page, System.UriKind.Relative));
            return null;
        }

        private void BackImage_Click(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            NavigationService.GoBack();
        }
    }
}