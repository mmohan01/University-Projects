using GalaSoft.MvvmLight;
using Scattr.Model;
using GalaSoft.MvvmLight.Command;
using System.Windows;
using GalaSoft.MvvmLight.Messaging;
using Scattr.Messages;
using System.Collections.Generic;
using System.Windows.Controls;
//using System.Collections.ObjectModel;

namespace Scattr.ViewModel
{
    /// <summary>
    /// This class contains properties that a View can data bind to.
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class ContactsViewModel : ViewModelBase
    {
        /// <summary>
        /// Initializes a new instance of the ContactsViewModel class.
        /// </summary>
        public ContactsViewModel()
        {
            // Crappy attempts to created business card objects.
            // Kept code in case I get anywhere with it in the future.
            //
            //string[] input = { "Ryan", "Reynolds", "Software Engineer", "IBM", "Hadoop", "Ruby", "Python", "C++" };
            //List<string> contacts = new List<string>(input);
            //
            //Image example = Source;
            //example.Source = "omoogm";
            //var image = new Image();
            //image.Source = "";
        }
    }
}