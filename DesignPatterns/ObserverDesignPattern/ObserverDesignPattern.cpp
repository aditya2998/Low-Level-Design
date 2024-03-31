/*

Problem statment : Consider you have some stock of items (iphones etc). 
There will be one "notifyMe" button for each items. 
Whoever clicked on notifyMe button, they will get notifications when that item will 
be available for sell.

Design notifyMe functionality
*/

#include<bits/stdc++.h>
using namespace std;

// Interface for Observer class
class NotificationAlertObserver {
public:
	virtual void update() {};
};

// Interface for observable class
class StocksObservable {
public:
	virtual int getStockCount() {};
	virtual void setStockCount(int newStockAdded) {};
	virtual void addStockData(NotificationAlertObserver &observer) {};
	virtual void removeStockData(NotificationAlertObserver observer) {};
	virtual void notifyObservers() {};
};

class IphoneObservable : public StocksObservable
{
private:
	list <NotificationAlertObserver *> listOfObservers;
	int stockCount = 0;

public:
	IphoneObservable() = default;
	~IphoneObservable() = default;
	int getStockCount()
	{
		return stockCount;
	}
	void setStockCount(int newStockAdded)
	{
		if (stockCount == 0)
		{
			notifyObservers();
		}
		stockCount += newStockAdded;
	}

	void addStockData(NotificationAlertObserver &observer)
	{
		listOfObservers.push_back(&observer);
		cout << "New observer added\n";
	}
	
	void removeStockData(NotificationAlertObserver observer)
	{
		//
	}

	void notifyObservers()
	{
		cout << "Notifying all the observers about new stock addition\n";
		for(NotificationAlertObserver *observer : listOfObservers)
		{
			observer->update();
		}
	}
};

class EmailAlertObserver : public NotificationAlertObserver
{
private:
	string emailID;
	StocksObservable observable;
public:
	EmailAlertObserver(const string emailID, StocksObservable &observable)
		: emailID(emailID), observable(observable) {}

	void update()
	{
		sendEmail("Product is in stock now. Hurry up.");
	}

	void sendEmail(string message)
	{
		cout << "Mail sent to emailID " << this->emailID << " with content : " << message << "\n";
	}
};

int main()
{
	StocksObservable *iphoneObservable = new IphoneObservable();

	NotificationAlertObserver *observer1 = new EmailAlertObserver("xyz@gmail.com", *iphoneObservable);
	NotificationAlertObserver *observer2 = new EmailAlertObserver("abc@gmail.com", *iphoneObservable);
	NotificationAlertObserver *observer3 = new EmailAlertObserver("def@gmail.com", *iphoneObservable);

	iphoneObservable->addStockData(*observer1);
	iphoneObservable->addStockData(*observer2);
	iphoneObservable->addStockData(*observer3);

	iphoneObservable->setStockCount(10);
	return 0;
}

