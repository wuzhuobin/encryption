
function ViKeySocketInterface()
{
	var u = document.URL;
    var url;
    var strSocketResult = '';
    if (u.substring(0, 5) == "https") 
	{
		url = "wss://localhost:81/test";
	}
	else 
	{
		url = "ws://localhost:81/test";
	}
    
    var ViKeySocket;

	if (typeof MozWebSocket != "undefined") 
	{
		ViKeySocket = new MozWebSocket(url);
	} 
	else 
	{
		this.ViKeySocket = new WebSocket(url);
	}
	
	this.ViKeySocket.onopen = function()
	{
		
	}
	
	this.Initialize = function() 
	{ 
		try
		{
			this.ViKeySocket.send('055');
			this.ViKeySocket.send('255' + '|222222' );
			return true;
		}
		catch(exception)
		{
			
		}
		
		return false;
	};   
	this.FindViKey = function() 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyFind",
				start: "start"
			};

			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;		
			
		}	
		catch(exception)
		{
			OutputLog('Error'+exception);
		}
		
		return false;		
	};
	
    this.VikeyGetHID = function(index) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyGetHID",
				Index: index
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyGetType = function(index) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyGetType",
				Index: index
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyGetLevel = function(index) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyGetLevel",
				Index: index
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyGetPtroductName = function(index) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyGetPtroductName",
				Index: index
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyUserLogin = function(index, UserPw) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyUserLogin",
				Index: index,
				UserPw: UserPw
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyAdminLogin = function(index, AdminPw) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyAdminLogin",
				Index: index,
				AdminPw: AdminPw
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeySetSoftIDString = function(index, SoftIDString) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeySetSoftIDString",
				Index: index,
				SoftIDString: SoftIDString
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyGetSoftIDString = function(index) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyGetSoftIDString",
				Index: index
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		
		return false;
	};
	
    this.VikeyReadData = function(index, Address, Length) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyReadData",
				Index: index,
				Address: Address,
				Length: Length
			};
	
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		return false;
	};
	
    this.VikeyWriteData = function(index, Address, Length, Data) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyWriteData",
				Index: index,
				Address: Address,
				Length: Length,
				Data: Data
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
			
		}
		return false;
	};
	
    this.Vikey3DesSetKey = function(index, Key) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "Vikey3DesSetKey",
				Index: index,
				Key: Key
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.Vikey3DesEncrypt = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "Vikey3DesEncrypt",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.Vikey3DesDecrypt = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "Vikey3DesDecrypt",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.VikeyDesSetKey = function(index, Key) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyDesSetKey",
				Index: index,
				Key: Key
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
	
    this.VikeyDesEncrypt = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyDesEncrypt",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.VikeyDesDecrypt = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyDesDecrypt",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
    this.VikeySetAutoRunUrl = function(index, Url) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeySetAutoRunUrl",
				Index: index,
				Url: Url
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.VikeyMD5 = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyMD5",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.VikeySetMD5Key = function(index, Key) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeySetMD5Key",
				Index: index,
				Key: Key
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
	
    this.VikeyHmacMD5 = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyHmacMD5",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
    this.VikeySHA1 = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeySHA1",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
    this.VikeyHmacSHA1 = function(index, Length, Text) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeyHmacSHA1",
				Index: index,
				Length: Length,
				Text: Text
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
    this.VikeySetSHA1Key = function(index, Key) 
	{
		try
		{
			var msg = 
			{
				FunctionType: "VikeySetSHA1Key",
				Index: index,
				Key: Key
			};
			this.ViKeySocket.send('255|ViKeyWebSocket|'+JSON.stringify(msg));
			return true;
		}	
		catch(exception)
		{
		}
		return false;
	};
}