using GalaSoft.MvvmLight;
using Scattr.Model;
using GalaSoft.MvvmLight.Command;
using System.Windows;
using GalaSoft.MvvmLight.Messaging;
using Scattr.Messages;
using System.Collections.ObjectModel;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains properties that a View can data bind to.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class LoginViewModel : ViewModelBase
    {
        /// <summary>
        /// Initializes a new instance of the LoginScreenViewModel class.
        /// </summary>

        private User user;
        private string userName;
        private string password;
        public string UserName
        {
            get { return userName; }
            set { userName = value; RaisePropertyChanged(() => UserName); }
        }
        public string Password
        {
            get { return password; }
            set { password = value; RaisePropertyChanged(() => Password); }
        }
        public LoginViewModel()
        {
            user = new User();

            GoToMainPageCommand = new RelayCommand(() =>
            {
                if (string.IsNullOrEmpty(userName)) { MessageBox.Show("Please Enter Username"); }
                else if (string.IsNullOrEmpty(password)) { MessageBox.Show("Please Enter Password"); /*TODO Password Validation stuff?*/}
                else
                {
                    user.UserName = userName;
                    user.Password = password;

                    Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "Events" });
                }
            });

            GoToRegisterPageCommand = new RelayCommand(() =>
            {
                Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "Register" });
            });
        }

        public RelayCommand GoToMainPageCommand
        {
            get;
            private set;
        }

        public RelayCommand GoToRegisterPageCommand
        {
            get;
            private set;
        }
    }
}