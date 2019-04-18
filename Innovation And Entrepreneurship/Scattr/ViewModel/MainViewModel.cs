using GalaSoft.MvvmLight;
using Scattr.Model;
using GalaSoft.MvvmLight.Command;
using System.Windows;
using GalaSoft.MvvmLight.Messaging;
using Scattr.Messages;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains properties that the main View can data bind to.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class MainViewModel : ViewModelBase
    {
        private readonly IDataService _dataService;

        /// <summary>
        /// The <see cref="WelcomeTitle" /> property's name.
        /// </summary>
        public const string WelcomeTitlePropertyName = "WelcomeTitle";

        private string _welcomeTitle = string.Empty;

        /// <summary>
        /// Gets the WelcomeTitle property.
        /// Changes to that property's value raise the PropertyChanged event. 
        /// </summary>
        public string WelcomeTitle
        {
            get
            {
                return _welcomeTitle;
            }

            set
            {
                if (_welcomeTitle == value)
                {
                    return;
                }

                _welcomeTitle = value;
                RaisePropertyChanged(WelcomeTitlePropertyName);
            }
        }

        /// <summary>
        /// Initializes a new instance of the MainViewModel class.
        /// </summary>
        public MainViewModel(IDataService dataService)
        {
            _dataService = dataService;
            _dataService.GetData(
                (item, error) =>
                {
                    if (error != null)
                    {
                        // Report error here
                        return;
                    }

                    WelcomeTitle = item.Title;
                });

            GoToUserProfilePageCommand = new RelayCommand(() =>
                {
                    Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "UserProfile" });
                });

            GoToCreateEventPageCommand = new RelayCommand(() =>
            {
               Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "CreateEvent" });
            });

            GoToLoginPageCommand = new RelayCommand(() =>
            {
                Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "Login" });
            });

            GoToContactsPageCommand = new RelayCommand(() =>
            {
                Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "Contacts" });
            });

            GoToContactDetailsPageCommand = new RelayCommand(() =>
            {
                Messenger.Default.Send<NavigateToPageMessage>(new NavigateToPageMessage() { PageName = "ContactDetails" });
            });
        }

        public RelayCommand GoToUserProfilePageCommand
        {
            get;
            private set;
        }

        public RelayCommand GoToLoginPageCommand
        {
            get;
            private set;
        }

        public RelayCommand GoToCreateEventPageCommand
        {
            get;
            private set;
        }

        public RelayCommand GoToContactsPageCommand
        {
            get;
            private set;
        }

        public RelayCommand GoToContactDetailsPageCommand
        {
            get;
            private set;
        }

        ////public override void Cleanup()
        ////{
        ////    // Clean up if needed

        ////    base.Cleanup();
        ////}
    }
}