using GalaSoft.MvvmLight;
using Scattr.Model;
using GalaSoft.MvvmLight.Command;
using System.Windows;
using GalaSoft.MvvmLight.Messaging;
using Scattr.Messages;
using System;
using System.Text.RegularExpressions;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains properties that a View can data bind to.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class RegisterViewModel : ViewModelBase
    {
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
        public string Email
        {
            get { return email; }
            set { email = value; RaisePropertyChanged(() => Email); }
        }

        public string Mobile
        {
            get { return mobile; }
            set { mobile = value; RaisePropertyChanged(() => Mobile); }
        }
        public static bool IsValidEmail(string strIn)
        {
            // Return true if strIn is in valid e-mail format.
            return Regex.IsMatch(strIn,
                   @"^(?("")("".+?""@)|(([0-9a-zA-Z]((\.(?!\.))|[-!#\$%&'\*\+/=\?\^`\{\}\|~\w])*)(?<=[0-9a-zA-Z])@))" +
                   @"(?(\[)(\[(\d{1,3}\.){3}\d{1,3}\])|(([0-9a-zA-Z][-\w]*[0-9a-zA-Z]\.)+[a-zA-Z]{2,6}))$");
        }
        /// <summary>
        /// Initializes a new instance of the RegisterScreenViewModel class.
        /// </summary>
        private string userName;
        private string password;
        private string email;
        private string mobile;

        private User user;
        public RegisterViewModel()
        {

            user = new User();

            GoToRegPageCompleteCommand = new RelayCommand(() =>
            {
                if (string.IsNullOrEmpty(userName)) { MessageBox.Show("Please Enter Username"); }
                else if (string.IsNullOrEmpty(password)) { MessageBox.Show("Please Enter Password"); /*TODO Password Validation stuff?*/}
                else if (string.IsNullOrEmpty(email) || !IsValidEmail(email)) { MessageBox.Show("Please Enter Valid E-mail Address"); }
                else if (string.IsNullOrEmpty(mobile)) { MessageBox.Show("Please Enter Mobile Number"); /*TODO Mobile Validation Stuff?*/}
                else
                {
                    user.UserName = userName;
                    user.Password = password;
                    user.Email = email;
                    user.Mobile = mobile;
                    //TODO Send details to server and then log in automatically
                    Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "Events" });
                }
            });
        }

        public RelayCommand GoToRegPageCompleteCommand
        {
            get;
            private set;
        }

    }
}