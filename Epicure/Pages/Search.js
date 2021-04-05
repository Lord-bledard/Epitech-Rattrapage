import React from 'react';
import {
    FlatList,
    StyleSheet,
    Text,
    TextInput,
    View
} from 'react-native';
import * as Constant from '../Constant';
import ImgurPost from '../Components/ImgurPost';

export default class Gallery extends React.Component {
    constructor() {
        super();
        this.searchedText = '';
        this.state = {
            isLoading: true,
            pageIndex: 0,
        };
    }

    callAPI(search) {
        const url = `https://api.imgur.com/3/gallery/search/top/?q=${search}`;
        
        const myHeaders = new Headers();
        myHeaders.append('Authorization', `Client-ID ${Constant.CLIENT_ID}`);

        const requestOptions = {
            methods: 'GET',
            headers: myHeaders,
            redirect: 'follow',
        };

        return fetch(url, requestOptions)
        .then(res => res.json())
        .then(json => {
            this.setState({
                dataSource: json.data.filter(el => el.is_album && el.images[0].type.startsWith('image'))
            });
        })
        .catch(err => console.log('ERROR', err));
    };

    loadResult() {
        if (this.searchedText.length > 0) {
            this.setState({ isLoading: true });
            this.callAPI(this.searchedText).then(() => {
                this.setState({ isLoading: false });
            });
        }
    }

    render() {
        return (
            <View>
                <Text style={styles.title}>Recherche</Text>
                <TextInput
                    style={styles.textInput}
                    placeholder='Rechercher'
                    onSubmitEditing={() => this.loadResult()}
                    onChangeText={text => {this.searchedText = text;}}
                />
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
    title: {
        fontSize: 40,
        fontWeight: 'bold',
    },
    textInput: {
        padding: 10,
        height: 40,
        borderWidth: 1,
        borderRadius: 5,
        borderColor: 'lightgrey',
    },
});
