using GalaSoft.MvvmLight;
using Scattr.Model;
using GalaSoft.MvvmLight.Command;
using System.Windows;
using GalaSoft.MvvmLight.Messaging;
using Scattr.Messages;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains properties that a View can data bind to.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class ContactDetailsViewModel : ViewModelBase
    {
        /// <summary>
        /// Initializes a new instance of the ContactDetailsViewModel class.
        /// </summary>
        public ContactDetailsViewModel()
        {
        }
    }
}