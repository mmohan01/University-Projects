using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Controls;

namespace Scattr.Model
{
    public class BusinessCard
    {

        #region Private variables
        private Image businessCard;
        private string foreName;
        private string surname;
        private string currentJob;
        private List<string> websites;
        private string linkedInURL;
        private string about;
        private string interests;
        private string businessCardToken;
        #endregion

        #region Getters & Setters
        public Image BusinessCardImage
        {
            get { return businessCard; }
            set { businessCard = value; }
        }

        public string Forename
        {
           get { return foreName; }
           set { foreName = value;}
        }

        public string Surname
        {
            get { return surname; }
            set { surname = value; }
        }

        public string CurrentJob
        {
            get { return currentJob; }
            set { currentJob = value; }
        }
        public List<string> Websites
        {
            get { return websites; }
            set { websites = value; }
        }

        public string LinkedInURL
        {
            get { return linkedInURL; }
            set { linkedInURL = value; }
        }

        public string About
        {
            get { return about; }
            set { about = value; }
        }

        public string Interests
        {
            get { return interests; }
            set { interests = value; }
        }

        public string BusinessCardToken
        {
            get { return businessCardToken; }
            set { businessCardToken = value; }
        }
        #endregion

    }
}