using System.Windows;
using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Scattr.Model;
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
    public class CreateEventViewModel : ViewModelBase
    {

        public string Name { get; set; }
        public string Description { get; set; }
        public DateTime StartDate { get; set; }
        public DateTime EndDate { get; set; }
        public DateTime StartTime { get; set; }
        public DateTime EndTime { get; set; }
        public string Website { get; set; }

        /// <summary>
        /// Initializes a new instance of the CreateEventViewModel class.
        /// </summary>
        public CreateEventViewModel()
        {
            Name = "";
            Description = "";
            StartDate = DateTime.UtcNow;
            EndDate = DateTime.UtcNow;
            StartTime = DateTime.UtcNow;
            EndTime = DateTime.UtcNow;
            Website = "";

            GoToEventCreatedPageCommand = new RelayCommand(() =>
            {
                // If it isn't valid input the user must try again.
                if (!VerifyUserEventInput())
                {
                    return;
                }

                // TODO: Do whatever we want to do when an event is created.
             
            });

        }

        public RelayCommand GoToEventCreatedPageCommand
        {
            get;
            private set;
        }

        // Returns true if input values satisfy the necessary conditions:
        // - Name isn't empty
        // - Description isn't empty
        // - StartDate comes before or on EndDate
        // - StartTime comes before EndTime
        // - If website isn't blank, it must be a valid URL
        // Else gives the user a message and returns false.
        private bool VerifyUserEventInput()
        {
            bool valid = true;
            string message = "Input not valid:\n";

            if (string.IsNullOrEmpty(Name))
            {
                message += " - Event Name must not be empty\n";
                valid = false;
            }
            if (string.IsNullOrEmpty(Description))
            {
                message += " - Description must not be empty\n";
                valid = false;
            }
            if (StartDate.Date > EndDate.Date)
            {
                message += " - Start date must precede end date\n";
                valid = false;
            }
            if (StartTime.TimeOfDay >= EndTime.TimeOfDay)
            {
                message += " - Start time must precede end time\n";
                valid = false;
            }
            if (!string.IsNullOrEmpty(Website) )
            {
                Uri uri;
                if (!Uri.TryCreate(Website, UriKind.Absolute, out uri))
                {
                    message += " - Website must be a valid URL\n";
                    valid = false;
                } 
            }
            if (!valid)
                MessageBox.Show(message);
                
            return valid;
        }
    }
}