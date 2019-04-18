using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Scattr.Model
{
    public class User
    {
        public string UserName { get; set; }
        public string Password { get; set; }
        public string Email { get; set; }
        public string Mobile { get; set; }
        public BusinessCard BusinessCard { get; set; }
    }
}
