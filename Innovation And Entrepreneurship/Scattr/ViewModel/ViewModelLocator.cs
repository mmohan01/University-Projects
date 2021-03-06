﻿/*
  In App.xaml:
  <Application.Resources>
      <vm:ViewModelLocatorTemplate xmlns:vm="clr-namespace:Scattr.ViewModel"
                                   x:Key="Locator" />
  </Application.Resources>
  
  In the View:
  DataContext="{Binding Source={StaticResource Locator}, Path=ViewModelName}"
*/

using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Ioc;
using Microsoft.Practices.ServiceLocation;
using Scattr.Model;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains static references to all the view models in the
    /// application and provides an entry point for the bindings.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class ViewModelLocator
    {
        static ViewModelLocator()
        {
            ServiceLocator.SetLocatorProvider(() => SimpleIoc.Default);

            if (ViewModelBase.IsInDesignModeStatic)
            {
                SimpleIoc.Default.Register<IDataService, Design.DesignDataService>();
            }
            else
            {
                SimpleIoc.Default.Register<IDataService, DataService>();
            }

            SimpleIoc.Default.Register<MainViewModel>();
            SimpleIoc.Default.Register<UserProfileViewModel>();
            SimpleIoc.Default.Register<CreateEventViewModel>();
            //SimpleIoc.Default.Register<LoginScreenViewModel>();
            SimpleIoc.Default.Register<ContactsViewModel>();
            //SimpleIoc.Default.Register<RegisterScreenViewModel>();
            SimpleIoc.Default.Register<LoginViewModel>();
            SimpleIoc.Default.Register<RegisterViewModel>();
            SimpleIoc.Default.Register<ContactDetailsViewModel>();
        }

        /// <summary>
        /// Gets the Main property.
        /// </summary>
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance",
            "CA1822:MarkMembersAsStatic",
            Justification = "This non-static member is needed for data binding purposes.")]
        public MainViewModel Main
        {
            get
            {
                return ServiceLocator.Current.GetInstance<MainViewModel>();
            }
        }

        /// <summary>
        /// Gets the UserProfileViewModel property.
        /// </summary>
        public UserProfileViewModel UserProfile
        {
            get
            {
                return ServiceLocator.Current.GetInstance<UserProfileViewModel>();
            }
        }
        
        /// <summary>
        /// Gets the CreateEventViewModel property.
        /// </summary>
        public CreateEventViewModel ViewModelCreateEvent
        {
            get
            {
                return ServiceLocator.Current.GetInstance<CreateEventViewModel>();
            }
        }

        /// <summary>
        /// Gets the LoginScreenViewModel property.
        /// </summary>
        public LoginViewModel LoginScreen
        {
            get
            {
                return ServiceLocator.Current.GetInstance<LoginViewModel>();
            }
        }

        /// <summary>
        /// Gets the ContactsViewModel property.
        /// </summary>
        public ContactsViewModel Contacts
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ContactsViewModel>();
            }
        }

        /// <summary>
        /// Gets the ContactDetailsViewModel property.
        /// </summary>
        public ContactDetailsViewModel ContactDetails
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ContactDetailsViewModel>();
            }
        }

        /// <summary>
        /// Gets the RegisterScreenViewModel property.
        /// </summary>
        public RegisterViewModel RegisterScreen
        {
            get
            {
                return ServiceLocator.Current.GetInstance<RegisterViewModel>();
            }
        }
        /// <summary>
        /// Cleans up all the resources.
        /// </summary>
        public static void Cleanup()
        {
        }
    }
}