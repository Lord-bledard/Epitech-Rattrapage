//client
#ifndef __CLIENT_HPP__
# define __CLIENT_HPP__

# include					<exception>
# include					<iostream>
# include					<vector>
# include					<algorithm>

class Client{
public:
	Client(void);
	~Client();

    void init(const char *, int, int);
	void run(void);

private:
	void setClient(void);
};

#endif                 /* !__CLIENT_HPP__ */