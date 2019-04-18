using GalaSoft.MvvmLight;
using Scattr.Model;
using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Resources;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using Scattr.Messages;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains properties that a View can data bind to.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class UserProfileViewModel : ViewModelBase
    {
        private User user;
        private ImageSource businessCardImage;
        private BusinessCard businessCard;
        private bool isEditMode;
        private string editSaveButtonText;

        public ImageSource BusinessCardImage
        {
            get { return businessCardImage; }
            set { businessCardImage = value; }
        }
        public string CurrentJob
        {
            get { return businessCard.CurrentJob; }
            set { businessCard.CurrentJob = value; RaisePropertyChanged(() => CurrentJob); }
        }
        public string Websites
        {
            get { return businessCard.Websites[0]; }
            set { businessCard.Websites[0] = value; RaisePropertyChanged(() => Websites); }
        }
        public string LinkedIn
        {
            get { return businessCard.LinkedInURL; }
            set { businessCard.LinkedInURL = value; RaisePropertyChanged(() => LinkedIn); }
        }
        public string About
        {
            get { return businessCard.About; }
            set { businessCard.About = value; RaisePropertyChanged(() => About); }
        }
        public string Interests
        {
            get { return businessCard.Interests; }
            set { businessCard.Interests = value; RaisePropertyChanged(() => Interests); }
        }
        public string EditSaveButtonText
        {
            get { return editSaveButtonText; }
            set { editSaveButtonText = value; RaisePropertyChanged(() => EditSaveButtonText); }
        }

        public bool IsEditMode
        {
            get { return isEditMode; }
            set
            {
                isEditMode = value;
                RaisePropertyChanged(() => IsEditMode);
            }
        }

        /// <summary>
        /// Initializes a new instance of the UserProfileViewModel class.
        /// </summary>
        public UserProfileViewModel()
        {
            isEditMode = true;
            editSaveButtonText = "Save";
            //About = "This is a section about the user";
            //CurrentJob = "This is the user's curent job";
            //Interests = "This is the user's interests";
            //Websites = "This is the user's websites";
            //LinkedIn = "This is the users LinkedIn URL";
            //Implemented after DLL connecting to MDB
            //user = GetUserByID(userID);
            //businessCard = user.BusinessCard;

            //businessCard = user.BusinessCard.BusinessCardImage;
            // This will all be replaced by above

            string fileName = "Assets/BusinessCard/RRBusinessCard.png";
            Uri uri = new Uri(fileName, UriKind.Relative);
            StreamResourceInfo resourceInfo = Application.GetResourceStream(uri);
            BitmapImage bmp = new BitmapImage();
            bmp.SetSource(resourceInfo.Stream);
            businessCardImage = bmp;

            InvokeEditModeCommand = new RelayCommand(() =>
            {
                if (IsEditMode)
                {
                    IsEditMode = false;
                    EditSaveButtonText = "Edit";
                    //TODO: Invoke database save
                }
                else
                {
                    IsEditMode = true;
                    EditSaveButtonText = "Save";
                }
            });
        }

        public RelayCommand InvokeEditModeCommand
        {
            get;
            private set;
        }

    }
}