import React from 'react';
import {
    ActivityIndicator,
    Button,
    FlatList,
    StyleSheet,
    Text,
    View
} from 'react-native';
import * as Constant from '../Constant';
import ImgurPost from '../Components/ImgurPost';

export default class Favorites extends React.Component {
    constructor() {
        super();
        this.state = {
            isLoading: true,
            username: 'Toramaa',
        };
    }

    componentDidMount() {
        this.callAPI(this.state.pageIndex);
    }

    callAPI(username) {
        const url = `https://api.imgur.com/3/account/${username}/favorites/`;
        
        const myHeaders = new Headers();
        myHeaders.append('Authorization', `Bearer ${Constant.ACCESS_TOKEN}`);

        const requestOptions = {
            methods: 'GET',
            headers: myHeaders,
            redirect: 'follow',
        };

        return fetch(url, requestOptions)
        .then(res => res.json())
        .then(json => {
            this.setState({
                isLoading: false,
                dataSource: json.data
            });
        })
        .catch(err => console.log('ERROR', err));
    };

    render() {
        if (this.state.isLoading) {
            return (
                <View>
                    <Text style={styles.title}>Favoris</Text>
                    <View style={styles.loadIndicator}>
                        <ActivityIndicator size='large' />
                    </View>
                </View>
            );
        }

        return (
            <View>
                <View style={styles.header}>
                    <Text style={styles.title}>Favoris</Text>
                    <Button
                        title='Actualiser'
                        onPress={() => this.callAPI(this.state.pageIndex)}
                    />
                </View>
                <FlatList
                    data={this.state.dataSource}
                    renderItem={ item => (
                        <ImgurPost post={item.item} />
                    )}
                />
            </View>
        );
    }
}

const styles = StyleSheet.create({
    header: {
        flexDirection: 'row',
        alignItems: 'center',
        justifyContent: 'space-between',
    },
    title: {
        fontSize: 40,
        fontWeight: 'bold',
    },
    loadIndicator: {
        flex: 1,
        justifyContent: 'center',
        alignItems: 'center',
    },
});
