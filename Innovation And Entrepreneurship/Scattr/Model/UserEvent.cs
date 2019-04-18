using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Scattr.Model
{
    public class UserEvent
    {
        // Required fields
        public string Name { get; set; }
        public string Description { get; set; }
        
        // StartDate and EndDate should use only the .Date property. They correspond to the dates the event will start and end.
        public DateTime StartDate { get; set; }
        public DateTime EndDate { get; set; }
       
        // StartTime and EndTime should use only the .TimeOfDay property. They correspond to the times on each day of the event that
        // it will start and end. For now just implementing it as 'every day is the same' but in complete app events will have fully
        // customisable timetables.
        public DateTime StartTime { get; set; }
        public DateTime EndTime { get; set; }
        
        // Optional fields
        public string Website { get; set; }

        public UserEvent()
        {
           
        }

 
    }
}
