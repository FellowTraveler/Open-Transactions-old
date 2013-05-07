using System;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace otvs
{
	using otapi = OpenTransactions.OTAPI;

    public sealed class Load
    {
        private static volatile Load instance;
        private readonly SetNative setNative = SetNative.Instance;
        private static object syncRoot = new Object();

        public static Load Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (syncRoot)
                    {
                        if (instance == null)
                        {
                            instance = new Load();
                        }
                    }
                }

                return instance;
            }
        }

        private Load() {
            var start = InitNative.Instance;
        }

        ~Load() {
            var finish = ShutdownNative.Instance;
        }

        private sealed class SetNative
        {
            [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
            [return: MarshalAs(UnmanagedType.Bool)]
            static extern bool SetDllDirectory(string lpPathName);


            private static volatile SetNative instance;
            private static object syncRoot = new Object();

            public static SetNative Instance
            {
                get
                {
                    if (instance == null)
                    {
                        lock (syncRoot)
                        {
                            if (instance == null)
                                instance = new SetNative();
                        }
                    }

                    return instance;
                }
            }

            private SetNative()
            {
                var path = Path.GetFullPath("..\\..\\..\\..\\..\\..\\lib\\Win32\\Debug");

                if (Directory.Exists(path))
                {
                    SetDllDirectory(path);
                }
            }
        }

        private sealed class InitNative
        {
            private static volatile InitNative instance;
            private static object syncRoot = new Object();

            public static InitNative Instance
            {
                get
                {
                    if (instance == null)
                    {
                        lock (syncRoot)
                        {
                            if (instance == null)
                                instance = new InitNative();
                        }
                    }

                    return instance;
                }
            }

            private InitNative()
            {
                var appStartup = otapi.OTAPI_Basic.AppStartup();
            }

        }

        private sealed class ShutdownNative
        {
            private static volatile ShutdownNative instance;
            private static object syncRoot = new Object();

            public static ShutdownNative Instance
            {
                get
                {
                    if (instance == null)
                    {
                        lock (syncRoot)
                        {
                            if (instance == null)
                                instance = new ShutdownNative();
                        }
                    }

                    return instance;
                }
            }

            private ShutdownNative()
            {
                var appStartup = otapi.OTAPI_Basic.AppShutdown();
            }
        }

    }
}
